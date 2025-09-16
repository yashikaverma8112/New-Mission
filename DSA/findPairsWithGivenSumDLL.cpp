// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int,int>>ans;
        
        Node * low = head;
        Node * high = head;
        
        while(high->next != NULL){
            high = high->next;
        }
        
        while(low->data < high->data){
            if(low->data + high->data == target){
                ans.push_back({low->data,high->data});
                low = low->next;
                high = high->prev;
            }
            else if(low->data + high->data < target){
                low = low->next;
            }
            else{
                high = high->prev;
            }
        }
        return ans;
    }
};
