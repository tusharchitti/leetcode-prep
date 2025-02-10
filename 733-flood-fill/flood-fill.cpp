class Solution {
public:

    void fill(vector<vector<int>>& image , int sr, int sc , int color , int start,vector<vector<int>> &visit)
    {
          //if(image[sr][sc] == 0) return;
          //cout<<sr <<" "<<sc<<endl;
          if(visit[sr][sc] == 1) return; 
          if(image[sr][sc] == start)
          {
          image[sr][sc] = color;
          }
          else
          {
            return;
          }
          
          visit[sr][sc] = 1;

          if(sr+1>=0 && sc>=0 && sr+1<image.size()  && sc<image[0].size())
          {
            fill(image, sr+1,sc,color, start, visit);
          }

          if(sr>=0 && sc+1>=0 && sr<image.size()  && sc+1<image[0].size())
          {
            fill(image, sr,sc+1,color,start,visit);
          }

          if(sr-1>=0 && sc>=0 && sr-1<image.size()  && sc<image[0].size())
          {
            fill(image, sr-1,sc,color,start,visit);
          }

          if(sr>=0 && sc-1>=0 && sr<image.size()  && sc-1<image[0].size())
          {
            fill(image, sr,sc-1,color,start,visit);
          }

          
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> dp(image.size(),vector<int>(image[0].size(),0));
        fill(image, sr,sc,color, image[sr][sc], dp);
        return image;
    }
};