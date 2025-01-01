
bool isNum(char i)
{
   return(i >='0' && i<='9');
}

bool isLower(char i)
{
    return (i>='a' && i<='z');
}

void multiply(map<string, int> &mp, int m)
{
    for(auto &pair :mp)
    {
         mp[pair.first] = pair.second*m;
    }
}

map<string, int> addMap(map<string, int>a, map<string, int>b)
{
  for(auto &pair :b)
  {
     if(a.find(pair.first) == a.end()){
        a[pair.first] = 0;
     }
     a[pair.first] = a[pair.first]+b[pair.first];
  }
  return a;
}

string MapToString(map<string, int>&a)
{
  string ans = "";
  for(auto key: a)
  {
    //cout<<key.first<<" "<<key.second<<endl;
    ans = ans + key.first;
    int val = a[key.first];
    string rev = "";
    while(val !=0)
    {
        int remainder = val%10;
        val= val/10;
        char c = '0'+ remainder;
        rev= rev + c;
    }
    if(rev!="1")
    {
        for(int i=rev.length()-1;i>=0;i--)
        {
            ans = ans + rev[i];
        }
    } 
  }
  return ans;
}

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string,int>> st;
        string ans="";
        if(formula[0] != '(' || formula[formula.size()-1]!=')')
        {
            formula = '(' + formula + ')';
        }
        for(int i=0;i<formula.size();i++)
        {
             if(formula[i] == '(')
             {
                // start of a new map.
                map<string,int> mp;
                st.push(mp);
             }
             else if(formula[i]==')')
             {
                // end of circle.
                map<string,int> mp = st.top();
                st.pop();
                int multi = 0;
                for(int j=i+1;j<formula.size();j++)
                {
                    if(isNum(formula[j]))
                    {
                        multi = multi*10 + (formula[j]-'0');
                        i = j;
                    }
                    else
                    {
                        break;
                    }
                }
                if(multi != 0)
                {
                    // iterate through map and multiple all the digits *multi
                    multiply(mp,multi);
                    ans = MapToString(mp); 
                }
                if(st.size() != 0)
                {
                    map<string,int> prev = st.top();
                    st.pop();
                    mp = addMap(mp,prev);
                    st.push(mp);
                }
                ans = MapToString(mp);
             }
             else
             {
                //its a char , it can vever be a numa s i always check that pre-emptly
                string c = "";
                char f = formula[i];
                c= c+f;
                for(int j=i+1;j<formula.size();j++)
                {
                     if(isLower(formula[j]))
                     {
                        c= c+ formula[j];
                        i =j;
                     }
                     else
                     {
                        break;
                     }
                }
                int count = 0;
                for(int j=i+1;j<formula.size();j++)
                {
                    if(isNum(formula[j]))
                    {
                        count = count*10 + (formula[j]-'0');
                        i = j;
                    }
                    else
                    {
                        break;
                    }
                }
                if(count == 0) count = 1;
                st.top()[c] = st.top()[c]+ count;
             }
        }
       return ans;
    }
};