#include <iostream>
#include <stdexcept>
#include <string>
#include "Board.hpp"
using namespace std;
namespace ariel{
    void Board::post(uint i, uint j, ariel::Direction d, string s){
        uint l=s.size();
        if(d==Direction::Horizontal){

                resize(max(i+1,this->row+1),max(j+l,this->col));
        }
        else{
                resize(max(i+l,this->row),max(j+1,this->col+1));
        }
        uint row=i;
        uint col=j;
        for(uint x=0; x<l; x++){
            this->m.at(row).at(col)=s[x];
            if(d==Direction::Horizontal){
                col++;
            }
            else{ 
              row++;
            }  

        }
    }

    void Board::resize(uint row, uint col){
        this->col=col;
        this->row=row;
    
        this->m.resize(row);
         for(ulong r=0; r<row;r++){
                this->m.at(r).resize(col,'_');
            }
    }
    string Board::read(uint i,uint j, ariel::Direction d, uint k){
        string ans;
        int index=0;
        while((i<this->row && k!=0 )&&( j<this->col &&k!=0)){   
            ans.push_back(this->m.at(i).at(j));
            if(d==Direction::Horizontal){
                j++;
            }
            else {
                i++;
            }
            k--;
        }
        while(k!=0){
               ans.push_back('_');
               k--;                          
           }
        return ans;
    }
    void Board::show(){
        for(uint i=0; i<this->row; i++){
            cout<<"\n";
            for(uint j=0; j<this->col; j++){
                cout << this->m[i][j];
            }
        }
    }
}