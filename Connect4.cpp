// code by RAMEEN AMIR 20l-1283
#include<iostream>
#include<string>

using namespace std;

int d;
struct connect4{

    connect4(string Names[]){
        re_init(Names);
    }

	connect4(){

	    string N[2] = {"P1", "P2"};

		cout<<"Enter Name for First Player: ";
		cin>>N[0];
		cout<<endl;

		cout<<"Enter Name for Second Player: ";
		cin>>N[1];
	    cout<<endl;

	    re_init(N);
    }

	void re_init(string Names[]){

	    for(int i = 0; i< 6; i++){
            for(int j = 0; j< 7; j++){
            	ColumnMoves[j] = 5;
                Data[i][j] = 32; // 32 is code of space character
     	   }
    	}

        Result = 0;
        GameOver = 0;
        PlayerNames[0] = Names[0];
        PlayerNames[1] = Names[1];
        PlayerChar[0] = 'o';
        PlayerChar[1] = 'x';
        PlayerWinningChar[0] = 'O';
        PlayerWinningChar[1] = 'X';
        TurningPlayer =0;
    }

    int  MakeMove(int Column){
    /*
        This Function must make a move in the Column given as a parameter
        The function will use the function GameOver() to mark is the game
        is completed and set the value of variables GameOver and Result.
        The function must also update the array ColumnMoves.

        The function must return 0 if the move has been made, 1 if the move
        is invalid (can not be done as the column is already filled) and 2
        if the game is already over.

        This function must also change the value of TurningPlayer if the move
        was successful;

    */
    	int r=ColumnMoves[Column],c=Column;
		if(GameOver==1) return 2;
    	if(ColumnMoves[Column]<0)
		{
			cout<<"\n\n -- Invalid Move -- Already Filled Block--\n\n";
			return 1;
    	}
		if(c>6 || r>5)
		{
			cout<<"\n\n -- Invalid Move -- \n\n";
			return 1;
		}
    	if(GameOver==0);
    	{
			WhosTurn();
			getPlayerName(TurningPlayer);
			if (TurningPlayer==0)
			{
				Data[ColumnMoves[Column]][Column]=PlayerChar[0];
				TurningPlayer=1;
			}
	    	else if (TurningPlayer==1)
			{
				Data[ColumnMoves[Column]][Column]=PlayerChar[1];
				TurningPlayer=0;
			}
			ColumnMoves[Column]-=1;
			ShowGame();

		}
		CheckIfGameOver(r,c);
}

    void ShowGame(){
    /*
        Function to display the game status on screen;
    */
    	cout<<"\n";
    	for(int i = 0; i< 6; i++){
            for(int j = 0; j< 7; j++)
                cout<<" | "<<Data[i][j];
   	        cout<<" | "<<endl<<" -----------------------------"<<endl;
	    }
	    cout<<"\n";
    }

    bool isGameOver(){
        return GameOver;
    }

    int  WhosTurn(){
        return TurningPlayer;
    }

    string getPlayerName(int id){

	    if(id< 0 || id > 1 )
            return "";
        return PlayerNames[id];
    }

private:

    bool CheckIfGameOver(int r, int c){
    /*
        This function will check if the game is finished and set the values
        of variables GameOver and Result
        The parameters r and c specify the position of last move last

    */
			int i=0;
			if(TurningPlayer==0) i=1;
			else if(TurningPlayer==1) i=0;
		    if( Data[r][c] == Data[r+1][c]  && Data[r][c] == Data[r+2][c]   && Data[r][c]  == Data[r+3][c]  )
			{
				Data[r][c] = Data[r+1][c] = Data[r+2][c] = Data[r+3][c] = PlayerWinningChar[i];
				GameOver=1;
			}
		    if( Data[r][c] == Data[r][c+1]  && Data[r][c] == Data[r][c+2]   && Data[r][c]  == Data[r][c+3]  )
			{
				Data[r][c] = Data[r][c+1] = Data[r][c+2] = Data[r][c+3] = PlayerWinningChar[i];
				GameOver=1;
			}
		    if( Data[r][c] == Data[r][c-1]  && Data[r][c] == Data[r][c+1]   && Data[r][c]  == Data[r][c+2]  )
			{
				Data[r][c] = Data[r][c-1] = Data[r][c+1] = Data[r][c+2] = PlayerWinningChar[i];
				GameOver=1;
			}
		    if( Data[r][c] == Data[r][c-1]  && Data[r][c] == Data[r][c-2]   && Data[r][c]  == Data[r][c+1]  )
			{
				Data[r][c] = Data[r][c-1] = Data[r][c-2] = Data[r][c+3] = PlayerWinningChar[i];
				GameOver=1;
			}
			if( Data[r][c] == Data[r][c-1]  && Data[r][c] == Data[r][c-2]   && Data[r][c]  == Data[r][c-3]  )
			{
				Data[r][c] = Data[r][c-1] = Data[r][c-2] = Data[r][c-3] = PlayerWinningChar[i];
				GameOver=1;
			}
			if( Data[r][c] == Data[r][c+1]  && Data[r][c] == Data[r][c-1]   && Data[r][c]  == Data[r][c-2]  )
			{
				Data[r][c] = Data[r][c+1] = Data[r][c-1] = Data[r][c-2] = PlayerWinningChar[i];
				GameOver=1;
			}
			if( Data[r][c] == Data[r][c+1]  && Data[r][c] == Data[r][c+2]   && Data[r][c]  == Data[r][c-1]  )
			{
				Data[r][c] = Data[r][c+1] = Data[r][c+2] = Data[r][c-1] = PlayerWinningChar[i];
				GameOver=1;
			}
		    if(Data[r][c] == Data[r+1][c+1] && Data[r][c] == Data[r+2][c+2] && Data[r][c]  == Data[r+3][c+3] )
			{
				Data[r][c]= Data[r+1][c+1] = Data[r+2][c+2] = Data[r+3][c+3] = PlayerWinningChar[i];
				GameOver=1;
			}
			if(Data[r][c] == Data[r-1][c-1] && Data[r][c] == Data[r+1][c+1] && Data[r][c]  == Data[r+2][c+2] )
			{
				Data[r][c]= Data[r-1][c-1] = Data[r+2][c+2] = Data[r+1][c+1] = PlayerWinningChar[i];
				GameOver=1;
			}
			if(Data[r][c] == Data[r-1][c-1] && Data[r][c] == Data[r-2][c-2] && Data[r][c]  == Data[r+1][c+1] )
			{
				Data[r][c]= Data[r-1][c-1] = Data[r-2][c-2] = Data[r+1][c+1] = PlayerWinningChar[i];
				GameOver=1;
			}
			if(Data[r][c] == Data[r-1][c-1] && Data[r][c] == Data[r-2][c-2] && Data[r][c]  == Data[r-3][c-3] )
			{
				Data[r][c] = Data[r-1][c-1] = Data[r-2][c-2] = Data[r-3][c-3] = PlayerWinningChar[i];
				GameOver=1;
			}
			if(Data[r][c] == Data[r+1][c+1] && Data[r][c] == Data[r-2][c-2] && Data[r][c]  == Data[r-1][c-1] )
			{
				Data[r][c] = Data[r+1][c+1] = Data[r-2][c-2] = Data[r-1][c-1] = PlayerWinningChar[i];
				GameOver=1;
			}
			if(Data[r][c] == Data[r+1][c+1] && Data[r][c] == Data[r+2][c+2] && Data[r][c]  == Data[r-1][c-1] )
			{
				Data[r][c] = Data[r+1][c+1] = Data[r+2][c+2] = Data[r-1][c-1] = PlayerWinningChar[i];
				GameOver=1;
			}
		    if(Data[r][c] == Data[r-1][c+1] && Data[r][c] == Data[r-2][c+2] && Data[r][c]  == Data[r-3][c+3] )
			{
				Data[r][c] = Data[r-1][c+1] = Data[r-2][c+2] = Data[r-3][c+3] = PlayerWinningChar[i];
				GameOver=1;
			}
			if(Data[r][c] == Data[r+1][c-1] && Data[r][c] == Data[r-2][c+2] && Data[r][c]  == Data[r-1][c+1] )
			{
				Data[r][c] = Data[r+1][c-1] = Data[r-2][c+2] = Data[r-3][c+3] = PlayerWinningChar[i];
				GameOver=1;
			}
		    if(Data[r][c] == Data[r+1][c-1] && Data[r][c] == Data[r+2][c-2] && Data[r][c]  == Data[r-1][c+1] )
			{
				Data[r][c] = Data[r+1][c-1] = Data[r+2][c-2] = Data[r-3][c+3] = PlayerWinningChar[i];
				GameOver=1;
			}
			if(Data[r][c] == Data[r+1][c-1] && Data[r][c] == Data[r+2][c-2] && Data[r][c]  == Data[r+3][c-3] )
			{
				Data[r][c] = Data[r+1][c-1] = Data[r+2][c-2] = Data[r+3][c-3] = PlayerWinningChar[i];
				GameOver=1;
			}
			if(Data[r][c] == Data[r-1][c+1] && Data[r][c] == Data[r+2][c-2] && Data[r][c]  == Data[r+1][c-1] )
			{
				Data[r][c] = Data[r-1][c+1] = Data[r+2][c-2] = Data[r+3][c-3] = PlayerWinningChar[i];
				GameOver=1;
			}
			if(Data[r][c] == Data[r-1][c+1] && Data[r][c] == Data[r-2][c+2] && Data[r][c]  == Data[r+1][c-1] )
			{
				Data[r][c] = Data[r-1][c+1] = Data[r-2][c+2] = Data[r+1][c-1] = PlayerWinningChar[i];
				GameOver=1;
			}

			if(d==42 && GameOver==0){
					Result=0;
				 	cout<<"-------------GAME DRAWN-------------\n";
					ShowGame();
					return isGameOver();
			}
	        if (GameOver==1)
			{
				if(i==0)
				{
					Result=1;
					cout<<"-------------Player 1 '' "<<getPlayerName(i)<<" '' is the WINNER-------------\n";
					ShowGame();
					return isGameOver();
				}
	        	else if(i==1)
				{

					Result=-1;
				 	cout<<"-------------Player 2 '' "<<getPlayerName(i)<<" '' is the WINNER-------------\n";
					ShowGame();
					return isGameOver();
				}
			}

    }

    string PlayerNames[2];     // To Hold Name of Players Who are playing
    int  TurningPlayer;        // To save the players ID who is making a move; 0: First Player, 1: Second Player
    char PlayerChar[2];        // Characters to be shown for move
    char PlayerWinningChar[2]; // Character to be shown if player wins.
    int  ColumnMoves[7];       // An array to keep record of first empty cell in a column
    char Data[6][7];           // Array to hold game data.
    bool GameOver;             // If true it means the game is over.
    int  Result;               // Variable to hold result of game {0: Drawn, -1: First Player Lost, 1: First Player Won}
};


int main(){
    /*
        This function use a single variable of type connect4
        and use it's functions to play the game
    */
    int b=1;
    do{
	    string N[2] = {"P1", "P2"};

	    cout<<"Enter Name for First Player: ";
		cin>>N[0];
		cout<<endl;

		cout<<"Enter Name for Second Player: ";
		cin>>N[1];
	    cout<<endl;

		connect4 ME(N);
		ME.ShowGame();
	    cout<<"\n''If you want to quit at any point press any negative number as your move''\n\n";

    	while(!ME.isGameOver())
		{

			cout<<ME.getPlayerName(ME.WhosTurn())<<" Turn :";
			int c=0;
			cin>>c;
			if(c<0)
			{
			 	cout<<"\n1) Press 0 to exit \n2) Press 1 to play again\n\n ";
	    		int a;
				cin>>a;
				if (a==0)
				{
					cout<<"\n''See You Soon''\n ";
					return 0;
			    }
			    else if(a==1)
			    	connect4();
			}
			ME.MakeMove(c);
			d+=1;

		}
	    cout<<"\n1) Press 0 to exit \n2) Press 1 to play again\n\n ";
		cin>>b;
		if (b==0)
		{
			cout<<"\n''See You Soon''\n ";
		    return ME.isGameOver();

	    }
	}while(b!=0);

    return 0;
}
