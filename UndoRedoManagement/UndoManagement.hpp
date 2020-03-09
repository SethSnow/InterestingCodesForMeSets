//
//  UndoManagement.hpp
//  MyProject01
//
//  Created by Xue Bai on 2020/3/8.
//  Copyright © 2020 Xue Bai. All rights reserved.
//

#ifndef UndoManagement_hpp
#define UndoManagement_hpp

#include <stdio.h>
#include <functional>
#include <tuple>

template<class classT, class ...Args>
class UndoManagement
{
public:
    UndoManagement(){};
    ~UndoManagement(){};
    
    void registUndoFunc(classT* targetClass, std::function<void(classT*, std::tuple<Args...>&)> targetFunc, std::tuple<Args...>& targetParams){
        if(m_targetClass != targetClass){
            m_targetClass = targetClass;
        }
        if(targetFunc != nullptr){
            m_targetFunc = targetFunc;
        }
        m_targetParams = targetParams;
        return;
    }
    
    void undo(){
        if(m_targetClass != nullptr && m_targetFunc != nullptr){
            m_targetFunc(m_targetClass, m_targetParams);
        }
        return;
    }
    void redo(){
        undo();
        return;
    }
    
private:
    classT* m_targetClass = nullptr;
    std::function<void(classT*, std::tuple<Args...>&)> m_targetFunc = nullptr;
    std::tuple<Args...> m_targetParams;
};


#endif /* UndoManagement_hpp */
