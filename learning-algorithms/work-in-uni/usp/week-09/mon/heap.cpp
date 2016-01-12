// push(heap, e) - log n
// pop(heap,) - log n
// top(heap) - 1
// merge (heap1, heap2) - log n
//

//
// pop се свежда до обединяваме. Изтриваме корена и извикваме  merge на двете поддървета.__amd64
// push:
//
// push се свежда отново до merge. Асо искам да добавя нов елемент си правя нов heap от новия елемент__amd64
struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int val= 0, Node* left = NULL, Node* right NULL): val(val), left(left), right(right){};
}

Node* merge(Node* left, Node* right)
{
  if(!left || !right) return left ? left : rifht; // проверяваме ако лявата е празна или дясната е празната върни тази, която е празна
  if(left -> val > rifht -> val) swap(left, right); // нека лявата ни пирамида да е с най малкия корен
  if(rand()&1) swap(left->left, left->right); // избираме случайно, което се грижи височината ни да е логаритъм от n
  left->right = Merge(left->right, right);
  return left;
}


Node* push(Node* heap, int el){
  return merge(heap, new Node(el));
}

int top(Node* heap;)
{
  return heap->val;
}

Node* pop(Node *heap)
{
  Node *left = heap -> left;
  Node *rifght = heap -> right;
  delete heap;
  return merge(left, right);
}
