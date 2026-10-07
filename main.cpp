#include <iostream>

void EvenAlgorithm(std::vector<std::vector<int>>& board, int n);
void OddAlgorithm(std::vector<std::vector<int>>& board, int n);
void DisplayBoard(std::vector<std::vector<int>>& board, int n, int sum_per_row);
int SumOfEachRow(int n);


int main() {
    int n = 1;
    int sum_per_row = 0;
    std::cout <<"Rules:\nEnter a number n, get back an n by n matrix that has numbers from 1 to n squared within itself.\n";
    std::cout<<"With each row adding up to the same number.\n: ";
    std::cin >>n;
    sum_per_row = SumOfEachRow(n);
    std::vector<std::vector<int>> board(n, std::vector<int>(n));

    for(int i = 0; i < 100; i++){
        std::cout <<'\n';
    }
    std::cout<<"-------\nn = "<<n<<"\n-------\n";
    if(n % 2 == 0){
        EvenAlgorithm(board, n);
    }
    else{
        OddAlgorithm(board, n);
    }
    DisplayBoard(board, n, sum_per_row);
    std::cout<<"-------\n";
    return 0;
}

int SumOfEachRow(int n){
    return (n * (n*n + 1))/2;
}

void DisplayBoard(std::vector<std::vector<int>>& board, int n, int sum_per_row){
    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++){
            if(column == n - 1){
                std::cout <<board[row][column];
                continue;
            }
            std::cout <<board[row][column]<<" + ";
        }
        std::cout<<" = "<<sum_per_row;
        std::cout<<std::endl;
    }
}

void EvenAlgorithm(std::vector<std::vector<int>>& board, int n){
    int temp = 1;
    int column = 0;
    do{
        for(int row = 0; row < n; row++){
            board[row][column] = temp;
            temp++;
        }
        column++;
        for(int row = n - 1; row > -1; row--){
            board[row][column] = temp;
            temp++;
        }
        column++;
    }while(temp < n * n);
}

void OddAlgorithm(std::vector<std::vector<int>>& board, int n){
    int number = 1;
    int row = 0;
    int column = 0;
    int boost = 0;
    do{
        column = 0;
        row = boost;
        for(int i = 0; i < n; i++){
            row %= n;
            board[row][column] = number;
            number++;
            row++;
            column++;
        }
        boost++;
    }while(number < n * n);
}