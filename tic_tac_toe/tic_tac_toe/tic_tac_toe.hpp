/*
 
 Design a tic tac toe game with a NxN board and K in a row,col,diag to win
 
 */

#include <string>
#include <unordered_map>

namespace TicTacToe{
    
    enum class Player{X,O};

    class Model {
    public:
        
        Model(int N, int K) : mySize{N},myWinLen{K} {}
        
        bool makeMove(int i, int j, Player player){
            if (i<0||i>=mySize||j<0||j>=mySize)
                return false;
            auto key=hash(i,j);
            if (myBoard.find(key)==myBoard.end()){
                myBoard[key]=player;
                return true;
            }else{
                return false;
            }
        }
        
        bool isWin(int i, int j) {
            auto key=hash(i,j);
            if (myBoard.find(key)==myBoard.end()) return false;
            //
            // try to find player's myWinLen
            //
            Player player=myBoard[key];
            auto col_cnt=0,row_cnt=0,beg=std::max(0,j-myWinLen+1),end=std::min(j+myWinLen,mySize-1);
            for (auto k=beg; k<=end; ++k){
                //
                // horizontal
                //
                auto col_key=hash(i,k); auto curr_col=myBoard.find(col_key);
                if (curr_col!=myBoard.end() && curr_col->second==player){
                    if (++col_cnt==myWinLen) return true;
                }else{
                    col_cnt=0;
                }
                //
                // vertical
                //
                auto row_key=hash(k,j); auto curr_row=myBoard.find(row_key);
                if (curr_row!=myBoard.end() && curr_row->second==player){
                    if (++row_cnt==myWinLen) return true;
                }else{
                    row_cnt=0;
                }
            }
            auto bottom_up_cnt=0,top_down_cnt=0;
            for (auto k=1-myWinLen; k<=myWinLen; ++k){
                //
                // bottom-up diagonal
                //
                auto bottom_up_key=hash(i-k,j+k); auto curr_bottom_up=myBoard.find(bottom_up_key);
                if (curr_bottom_up!=myBoard.end() && curr_bottom_up->second==player){
                    if (++bottom_up_cnt==myWinLen) return true;
                }else{
                    bottom_up_cnt=0;
                }
                //
                // top-down diagonal
                //
                auto top_down_key=hash(i+k,j+k); auto curr_top_down=myBoard.find(top_down_key);
                if (curr_top_down!=myBoard.end() && curr_top_down->second==player){
                    if (++top_down_cnt==myWinLen) return true;
                }else{
                    top_down_cnt=0;
                }
            }
            
            //
            // player's myWinLen NOT found
            //
            return false;
        }
        
        int getSize() const { return mySize; }
        
        int getWinLen() const { return myWinLen; }
        
    private:
        int mySize;
        int myWinLen;
        std::unordered_map<std::string,Player> myBoard;
        
        std::string hash(int i, int j) const {
            return std::to_string(i).append(",").append(std::to_string(j));
        }
    };
}
