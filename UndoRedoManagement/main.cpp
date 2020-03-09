//
//  main.cpp
//  MyProject01
//
//  Created by Xue Bai on 2019/12/14.
//  Copyright © 2019 Xue Bai. All rights reserved.
//

#include <iostream>
#include <tuple>
#include "UndoManagement.hpp"

using namespace std;

class TestUndoClassA{
public:
  
    virtual void testUndoRedoFunc(int level, UndoManagement<TestUndoClassA, int>& undoManagement){
        cout << "TestUndoClassA !" << endl;
        static std::tuple<int> tmp;
        tmp = std::make_tuple(getLevel());
        undoManagement.registUndoFunc(this, [&](TestUndoClassA* p, std::tuple<int>& t)->void{
            p->testUndoRedoFunc(get<0>(t), undoManagement);
            return;
        }, tmp);
        
        setLevel(level);
        return;
    };
    
    void setLevel(int level){ m_level = level; }
    int getLevel() const { return m_level; }
    
private:
    int m_level = 12;
};


class TestUndoClassB : public TestUndoClassA{
public:
    TestUndoClassB(){setLevel(34);}
    
    virtual void testUndoRedoFunc(int level, UndoManagement<TestUndoClassA, int>& undoManagement){
        cout << "TestUndoClassB !" << endl;
        static std::tuple<int> tmp;
        tmp = std::make_tuple(getLevel());
        undoManagement.registUndoFunc(this, [&](TestUndoClassA* p, std::tuple<int>& t)->void{
            p->testUndoRedoFunc(get<0>(t), undoManagement);
            return;
        }, tmp);
        setLevel(level);
        return;
    }
};

////////////////////////////////////////////////////
int main(int argc, const char * argv[]) {
    // insert code here...
  
    UndoManagement<TestUndoClassA> undo;
    
    TestUndoClassA* pta = new TestUndoClassA();
    TestUndoClassA* ptb = new TestUndoClassB();
    UndoManagement<TestUndoClassA, int> undoManagement;
    
    cout << "pta start !" << endl;
    pta->setLevel(30);
    cout << "pta level: " << pta->getLevel() << endl;
    
    cout << "pta testUndoRedoFunc !" << endl;
    pta->testUndoRedoFunc(40, undoManagement);
    cout << "pta level: " << pta->getLevel() << endl;
    
    
    cout << "pta redo !" << endl;
    undoManagement.redo();
    cout << "pta level: " << pta->getLevel() << endl;
    
    
    cout << "pta undo !" << endl;
    undoManagement.undo();
    cout << "pta level: " << pta->getLevel() << endl;

    
    cout << "pta redo !" << endl;
    undoManagement.redo();
    cout << "pta level: " << pta->getLevel() << endl;
    
    cout << "pta end !" << endl;
    
    cout << "-------------------------" << endl;
    
    cout << "ptb start !" << endl;
    ptb->setLevel(11);
    cout << "ptb level: " << ptb->getLevel() << endl;
    
    cout << "ptb testUndoRedoFunc !" << endl;
    ptb->testUndoRedoFunc(14, undoManagement);
    cout << "ptb level: " << ptb->getLevel() << endl;
    
    
    cout << "ptb redo !" << endl;
    undoManagement.redo();
    cout << "ptb level: " << ptb->getLevel() << endl;
    
    
    cout << "ptb undo !" << endl;
    undoManagement.undo();
    cout << "ptb level: " << ptb->getLevel() << endl;

    
    cout << "ptb redo !" << endl;
    undoManagement.redo();
    cout << "ptb level: " << ptb->getLevel() << endl;
    
    cout << "ptb end !" << endl;
    
    if(pta != nullptr){
        delete pta;
        pta = nullptr;
    }
    
    if(ptb != nullptr){
        delete ptb;
        ptb = nullptr;
    }

    return 0;
}
