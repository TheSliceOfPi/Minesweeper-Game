#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int bSize;
int totalbmb;
void display(string brdGame[][30]){
    cout<<"  ";
    for(int k=0;k<bSize;k++){
        cout<<k;
    }
    cout<<""<<endl;
    for (int i=0;i<bSize;i++){
        cout<<i;
        cout<<" ";
        for(int j=0;j<bSize;j++){
            cout<< brdGame[i][j];
        }
        cout<<""<<endl;
    }
    return;
}
void setBmb(string answrs[][30]){
    int b=0;
    while(b<totalbmb){
        int row=rand()%bSize;
        int col=rand()%bSize;
        //cout<<row;
        //cout<<col<<endl;
        if(answrs[row][col]!="*"){
            answrs[row][col]="*";
            b=b+1;
        }
    }
    return;
}
int checkArea(int x, int y, string aBoard[][30]){
    int count=0;
    for (int i=0;i<=2;i++){
        for (int j=0;j<=2;j++){
            if((x+1-i)>=0 && (x+1-i)<bSize && (y+1-j)>=0 && (y+1-j)<bSize){
                if(aBoard[x+1-i][y+1-j]=="*"){
                    count=count+1;
                }
            }
        }
    }
    //cout<<count<<endl;
    return count;

}
int checkPlaying(string playerBoard[][30],string answerBoard[][30]){
    for(int i=0;i<bSize;i++){
        for (int j=0;j<bSize;j++){
            if(playerBoard[i][j]=="-" && answerBoard[i][j]!="*" ){
                return 0;
            }
        }
    }
    return 1;
}
int playMineSweeper(string answerBoard[][30],string playerBoard[][30]){
    int playing=1;
    int row=rand()%bSize;
    int col=rand()%bSize;
    while(playing){
        while (playerBoard[row][col]!="-"){
            cout << "You've already selected that position. Try a new position" << endl;
            cout << "Please choose a row" << endl;
            cin >> row;
            while(row>=bSize || row<0){
                cout << "Row out of bound. Choose a new row" << endl;
                cin >> row;
            }
            cout << "Please choose a column" << endl;
            cin >> col;
            while(col>=bSize || col<0){
                cout << "Column out of bound. Choose a new Column." << endl;
                cin >> col;
            }
        }
        if(answerBoard[row][col]=="*")
        {
            playerBoard[row][col]="*";
            display(playerBoard);
            return 0;
        }
        else{
            int bmbAround=checkArea(row,col,answerBoard);
            playerBoard[row][col]=to_string(bmbAround);
            display(playerBoard);
        }
        int finish=checkPlaying(playerBoard,answerBoard);
        if(finish){
            return 1;
        }
        
        cout << "Please choose a row" << endl;
        cin >> row;
        while(row>=bSize || row<0){
            cout << "Row out of bound. Choose a new row" << endl;
            cin >> row;
        }
        cout << "Please choose a column" << endl;
        cin >> col;
        while(col>=bSize || col<0){
            cout << "Column out of bound. Choose a new Column." << endl;
            cin >> col;
        }
    }
    return playing;
}
int main(){
    int x;
    cout<<"Welcome To Minesweeper!"<<endl;
    cout<<"What level would you like to play in?[1(Easy) to 3 (Difficult)]"<<endl;
    cin >> x;
    while (x > 3 || x < 1)
    {
         cout<<"Level out of range. Please choose a level between 1 and 3"<<endl;
         cout<<"What level would you like to play in?[1(Easy) to 3 (Difficult)]"<<endl;
         cin >> x;
    }
    totalbmb=5*x;
    bSize=5*x;
    cout<<"There is "<<totalbmb <<" mines in this "<< bSize << " by " << bSize << " board"<< endl;
    //Set Player Board
    //Set Answer Board
    string answerBoard[30][30];
    string playerBoard[30][30];
    for (int i= 0 ;i<bSize;i++){
        for (int j=0;j<bSize;j++){
            answerBoard[i][j]= "-";
            playerBoard[i][j]= "-";
        }
    }
    setBmb(answerBoard);
    int result=playMineSweeper(answerBoard,playerBoard);
    if(!result){
        cout << "You lost" << endl;
    }
    else{
        cout << "You won!"<<endl;
    }

    return 0;
}

