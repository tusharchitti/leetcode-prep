class Solution {
public:
    int getEmptySpots(vector<string>& words, int start, int end,int maxWidth)
    {
        for(int i=start;i<=end;i++)
          { 
             maxWidth = maxWidth - words[i].size();;
          }
          maxWidth = maxWidth - (end - start);
          cout<<start<<" "<<end<<" "<<maxWidth<<endl;
          return maxWidth;
    }

    bool isPossibleToJustify(vector<string>& words, int start, int end,int maxWidth)
    {
          return getEmptySpots(words,start,end,maxWidth)>=0;
    }
    
    string getEmptyString(int length)
    {
        string empty = "";
        for(int i=0;i<length;i++)
        {
           empty = empty + " ";
        }
        return empty;
    }

    string justifyLine(vector<string>& words, int start, int end,int maxWidth, bool isLast)
    {
        string justifyString = "";
        int remainingLength = getEmptySpots(words,start,end,maxWidth)+ (end-start);
        int spaceLength = remainingLength;
        int higherspaceIndex = 0;
        if(start != end)
        {
            spaceLength = remainingLength/(end-start);
            higherspaceIndex = remainingLength%(end-start);
        }
        if(isLast)
        {
            spaceLength = 1; 
            higherspaceIndex = 0;
        }
        for(int i=start;i<=end;i++)
          { 
            justifyString = justifyString + words[i];
            if(i!=end){
                string empty = "";
                if(higherspaceIndex>0)
                {
                    empty = getEmptyString(spaceLength+1);
                }
                else
                {
                    empty = getEmptyString(spaceLength);
                }
                justifyString =  justifyString+ empty;
            }
            higherspaceIndex--;
          }
          if(!isLast && start == end)
          {
            justifyString = justifyString+getEmptyString(spaceLength);
          }
          if(isLast)
          {
            justifyString = justifyString+getEmptyString(maxWidth-justifyString.size());
          }
        return justifyString;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justifiedWords;
        int start = 0;
        int end = 0;

        while(end<words.size())
        {
          int prev = end;
          while(end<words.size() &&  isPossibleToJustify(words, start , end, maxWidth))
          {
            prev = end;
            end++;
          }
          if(end == words.size() )
          justifiedWords.push_back(justifyLine(words,start,prev,maxWidth,true));
          else
          justifiedWords.push_back(justifyLine(words,start,prev,maxWidth,false));
          start = prev+1;
        }

        return justifiedWords;
    }
};