class TextEditor {
public:
    deque<char>left,right;
    TextEditor() {
        
    }
    
    void addText(string text) {
        left.insert(left.end(),text.begin(),text.end());
    }
    
    int deleteText(int k) {
        int cnt{};
        while(k-- and !left.empty())
        {
            left.pop_back();
            cnt++;
           
        }
        return cnt;
    }
    
    
    string cursorLeft(int k) {
        while(k-- and !left.empty())
        {
            right.push_back(left.back());
            left.pop_back();
          
        }
        return curtoleft();
    }
    
    string cursorRight(int k) {
         while(k-- and !right.empty())
        {
            left.push_back(right.back());
            right.pop_back();
          
        }
        return curtoleft();

    }
    
    string curtoleft()
    {
            if(left.size()<=10){
                return string(left.begin(),left.end());
            }
        return string(max(left.end()-10,left.begin()),left.end());
    }
};

// /**
//  * Your TextEditor object will be instantiated and called as such:
//  * TextEditor* obj = new TextEditor();
//  * obj->addText(text);
//  * int param_2 = obj->deleteText(k);
//  * string param_3 = obj->cursorLeft(k);
//  * string param_4 = obj->cursorRight(k);
//  */

