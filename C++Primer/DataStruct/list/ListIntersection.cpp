struct LNode{
    char data;
    LNode *next;
};

//判断是否有环
int listCircle(LNode *list)
{
    assert(list != NULL);
    LNode *first = list -> next -> next;
    LNode *second = list -> next;
    while(second != NULL)
    {
        if(first != second){
            first = first -> next;
            second = second -> next;
        }else{
            return 1;
        }
    }
    if(second == NULL){
        return 0;
    }
}

LNode *listIntersection(LNode *listOne, LNode *ListTwo)
{
    if(((listCircle(listOne) ^ listCircle(Two))) == 1){
        cout << "No intersection node here" << endl;
    }
    
    if(((listCircle(listOne) & listCircle(Two))) == 1){
        cout << "Both list are has list circle" << endl;
        LNode *lastOne, *lastTwo;
        LNode *currOne, *currTwo;
        currOne = listOne;
        currTwo = listTwo;

        while(currOne){
            lastOne = currOne;
            currOne = currOne -> next;
        }
        while(currTwo){
            lastTwo = currTwo;
            currTwo = currTwo -> next;
        }
        if(currOne -> data == currTwo -> data){
            cout << "Has the same node" << endl;
        }else{
            cout << "No such Node" << endl;
        }
    }

    if(((listCircle(listOne)) & listCircle(listTwo)) == 0){
        int lenOne = 0;
        int lenTwo = 0;
        int subList = 0;
        LNode *currOne = listOne;
        LNode *currTwo = listTwo;

        while(currOne != NULL){
            lenOne ++;
        }
        while(currTwo != NULL){
            lenTwo ++;
        }
        
        currOne = listOne;
        currTwo = listTwo;
        
        if(lenOne > lenTwo){
            subList = lenOne - lenTwo;

            int count = 0;
            while(count != subList){
                count ++;
                currOne = currOne -> next;
            }

            while(currOne != NULL){
                if(currOne -> data != currTwo -> data){
                    currOne = currOne -> next;
                    currTwo = currTwo -> next;
                }
            }
        }
    }
}
