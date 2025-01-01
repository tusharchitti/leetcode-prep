
bool isNum(char i)
{
   return(i >='0' && i<='9');
}

bool isLower(char i)
{
    return (i>='a' && i<='z');
}

map<string, int> multiply(map<string, int> mp, int m)
{
    for(auto &pair :mp)
    {
         mp[pair.first] = pair.second*m;
    }
    return mp;
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

string MapToString(map<string, int>a)
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
  cout<<ans<<endl;
  return ans;
}

class Solution {
public:
    string countOfAtoms(string formula) {
        cout<<formula<<endl;
        stack<map<string,int>> st;
        string ans="";
        if(formula[0] != '(' || formula[formula.size()-1]!=')')
        {
            formula = '(' + formula + ')';
        }
        cout<<formula<<endl;
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
                cout<<"Hi"<<endl;
                map<string,int> mp = st.top();
                st.pop();
                cout<<"removed"<<endl;
                int multi = 0;
                int counter = 1;
                for(int j=i+1;j<formula.size();j++)
                {
                    if(isNum(formula[j]))
                    {
                        multi = multi*10 + (formula[j]-'0');
                        counter= counter*10;
                        i = j;
                    }
                    else
                    {
                        break;
                    }
                }
                cout<<"m :"<<multi<<endl;
                if(multi != 0)
                {
                    // iterate through map and multiple all the digits *multi
                    mp = multiply(mp,multi);
                    ans = MapToString(mp); 
                }
                if(st.size() != 0)
                {
                    map<string,int> prev = st.top();
                    st.pop();
                    mp = addMap(mp,prev);
                    st.push(mp);
                }
                cout<<"here"<<endl;
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
                int counter = 1;
                for(int j=i+1;j<formula.size();j++)
                {
                    if(isNum(formula[j]))
                    {
                        count = count*counter + (formula[j]-'0');
                        counter= counter*10;
                        i = j;
                    }
                    else
                    {
                        break;
                    }
                }
                if(count == 0) count = 1;
                cout<<c<<" "<<count<<endl;
                st.top()[c] = st.top()[c]+ count;
             }
        }
       return ans;
    }
};