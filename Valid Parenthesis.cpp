Link:https://www.codingninjas.com/studio/guided-paths/data-structures-algorithms/content/651074/offering/10442135?leftPanelTabValue=SUBMISSION&customSource=studio_nav
Code:

bool isValidParenthesis(string expression)
{
  	 stack<char> s;
     for(int i=0; i<expression.length(); i++) {
         char ch = expression[i];
         if(ch == '(' || ch == '{' || ch == '['){
             s.push(ch);
         }
         else
         {
             if(!s.empty()) {
                  char top = s.top();
                  if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      s.pop();
                  }
                 else
                 {
                     return false;
                 }
             }
             else
             {
                 return false;
             } 
         }  
     }
    
    if(s.empty())
        return true;
    else
        return false;
}
