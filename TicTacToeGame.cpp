#include <iostream>;
#include <ctime>;

void drawBoard(char *spaces);
void playerMoves(char *spaces, char player);
void computerMoves(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);


int main(){
    char spaces[9] ={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer ='O';
    bool flag = true;

    drawBoard(spaces);

    while (flag){
        playerMoves(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player,computer))
        {
            flag = false;
            break;  
        }else if(checkTie(spaces)){
            flag = false;
            break;
        }
        
        computerMoves(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player,computer))
        {
            flag = false;
            break;  
        }else if(checkTie(spaces)){
            flag = false;
            break;
        }
    }
    
   

    return 0;
}

void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "   |   |   "<< '\n';
    std::cout << " "<< spaces[0]<<" "<< "|" << " "<< spaces[1]<<" "<< "|" << " "<< spaces[2]<<" "<<'\n';
    std::cout << "___|___|___"<< '\n';
    std::cout << "   |   |   "<< '\n';
    std::cout << " "<< spaces[3]<<" "<< "|" << " "<< spaces[4]<<" "<< "|" << " "<< spaces[5]<<" "<<'\n';
    std::cout << "___|___|___"<< '\n';
    std::cout << "   |   |   "<< '\n';
    std::cout << " "<< spaces[6]<<" "<< "|" << " "<< spaces[7]<<" "<< "|" << " "<< spaces[8]<<" "<<'\n';
    std::cout << '\n';
}

void playerMoves(char *spaces, char player){
    int number;
    do{
        std::cout << "Enter a spot to place a marker(1-9): ";
        std::cin >> number;
        number--;
        if (spaces[number] ==' '){
            spaces[number] = player;
            break;
        }     
    } while (number < 0 || number > 8);   
}

void computerMoves(char *spaces, char computer){
    int number;
    srand(time(0));

    while (true){
        number = rand()%9;
        if (spaces[number] ==' '){
            spaces[number] = computer;
            break;
        }    
    }
    std::cout<<"Thanks for play";
    
}
bool checkWinner(char *spaces, char player, char computer){
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player? std::cout<< "You Win!\n" : std::cout<< "You Loss.\n"; 
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player? std::cout<< "You Win!\n" : std::cout<< "You Loss.\n"; 
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player? std::cout<< "You Win!\n" : std::cout<< "You Loss.\n"; 
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player? std::cout<< "You Win!\n" : std::cout<< "You Loss.\n"; 
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player? std::cout<< "You Win!\n" : std::cout<< "You Loss.\n"; 
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player? std::cout<< "You Win!\n" : std::cout<< "You Loss.\n"; 
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player? std::cout<< "You Win!\n" : std::cout<< "You Loss.\n"; 
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player? std::cout<< "You Win!\n" : std::cout<< "You Loss.\n"; 
    } else{
        return false;
    }
    return true;
}

bool checkTie(char *spaces){
    for (int i = 0; i < sizeof(spaces); i++){
        if (spaces[i] == ' '){
            return false;
        }     
    }
    std::cout << "It's a Tie\n";
    return true;
}
