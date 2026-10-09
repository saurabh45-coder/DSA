class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        
        int row=0;
        int col =0;
         for(string command : commands)
         {
            if(command == "RIGHT")
            {
                if(col+1 < n)
                {
                    col++;
                }
            }
            else if(command == "LEFT")
            {
                if(col - 1 >= 0)
                {
                    col--;
                }
            }
            else if(command == "UP")
            {
                if(row -1 >= 0)
                {
                    row--;
                }
            }
            else if(command == "DOWN")
            {
                if(row +1 < n)
                {
                    row++;
                }
            }
         }
         return (row * n) +col;
    }
};