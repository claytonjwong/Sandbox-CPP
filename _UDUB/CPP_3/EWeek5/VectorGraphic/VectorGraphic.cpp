//
//  VectorGraphic.cpp
//  EWeek1
//
//  Created by CLAYTON WONG on 7/16/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include "VectorGraphic.hpp"
#include "Point.hpp"
#include <exception>
#include <list>

using namespace std;

namespace VG
{

    
    VectorGraphic::VectorGraphic() :
    myShapeStyle{ ShapeStyle::Close }
    {
    }

    
    BitmapGraphics::HStroke VectorGraphic::getStroke ( ) const noexcept
    {
        return myStroke;
    }
    
    
    void VectorGraphic::setStroke ( BitmapGraphics::HStroke stroke ) noexcept
    {
        myStroke = stroke;
    }
    
    
    void VectorGraphic::addPoint ( const Point& point )
    {
        myPath.push_back( point );
    }
    
    
    void VectorGraphic::addPoint ( Point&& point )
    {
        myPath.emplace_back(  forward<Point>( point )  );
    }
    
    
    void VectorGraphic::erasePoint ( int index )
    {
        if (  ( index >= 0 )  &&  ( static_cast<size_t>( index ) < getPointCount() )  )
        {
            auto pos = myPath.begin() + index;
            myPath.erase( pos );
        }
        else
        {
            throw out_of_range{ "index out of range" };
        }
    }
    
    
    void VectorGraphic::removePoint ( const Point& target )
    {
        auto newEnd = remove( myPath.begin(), myPath.end(), target );
        if ( newEnd != myPath.end() )
        {
            myPath.erase( newEnd, myPath.end() );
        }
        else
        {
            throw invalid_argument{ "the point to remove does not appear in the vectorgraphic." };
        }
    }
    
    
    void VectorGraphic::openShape() noexcept
    {
        myShapeStyle = ShapeStyle::Open;
    }
    
    
    void VectorGraphic::closeShape() noexcept
    {
         myShapeStyle = ShapeStyle::Close;
    }
    
    
    bool VectorGraphic::isClosed() const noexcept
    {
        return ! ( isOpen() );
    }
    
    
    bool VectorGraphic::isOpen() const noexcept
    {
        return myShapeStyle == ShapeStyle::Open;
    }

    
    Point VectorGraphic::getPoint ( int index ) const
    {
        return myPath.at( index ); // throws std::out_of_range if index out of range
    }
    
    
    size_t VectorGraphic::getPointCount() const noexcept
    {
        return myPath.size();
    }
    
    
    int VectorGraphic::getHeight() const noexcept
    {
        if ( getPointCount() > 0 )
        {
            auto [minIt, maxIt] = minmax_element( myPath.begin(), myPath.end(),
                []( const Point& lhs, const Point& rhs ){return lhs.getY() < rhs.getY();  });
            return maxIt->getY() - minIt->getY();
        }
        else
        {
            return 0;
        }
    }
    
    
    int VectorGraphic::getWidth() const noexcept
    {
        if ( getPointCount() > 0 )
        {
            auto [minIt, maxIt] = minmax_element( myPath.begin(), myPath.end(),
                []( const Point& lhs, const Point& rhs ){return lhs.getX() < rhs.getX();  });
            return maxIt->getX() - minIt->getX();
        }
        else
        {
            return 0;
        }
    }
    
    
    PathIterator VectorGraphic::begin() const noexcept
    {
        return myPath.begin();
    }
    

    PathIterator VectorGraphic::end() const noexcept
    {
        return myPath.end();
    }
    
    
    void VectorGraphic::Draw ( BitmapGraphics::HCanvas canvas, const Point& offset ) const
    {
        if ( myPath.empty() )
        {
            return;
        }
        
        auto pen = myStroke->createPen();
        
        auto currPoint = myPath.begin(), nextPoint = next( currPoint );
        do
        {
            Point absoluteCurr{ currPoint->getX() + offset.getX(), currPoint->getY() + offset.getY() };
            Point absoluteNext{ nextPoint->getX() + offset.getX(), nextPoint->getY() + offset.getY() };
            
            Utility::LineIterator lineIt{ absoluteCurr, absoluteNext };
            
            pen->drawPoint( canvas, lineIt.getCurrentPoint() );
            while ( ! lineIt.isEnd() )
            {
                lineIt.nextPoint();
                pen->drawPoint( canvas, lineIt.getCurrentPoint() );
            }
            
            currPoint = nextPoint;
            nextPoint = next( nextPoint );
            
        } while ( nextPoint != myPath.end() );
        
    }
    
    
    bool operator== ( const VectorGraphic& lhs, const VectorGraphic& rhs )
    {
        return ( lhs.myPath == rhs.myPath )
            && ( lhs.myShapeStyle == rhs.myShapeStyle );
    }
    
    
    bool operator!= ( const VectorGraphic& lhs, const VectorGraphic& rhs )
    {
        return ! ( lhs == rhs );
    }

    
} // namespace VG
