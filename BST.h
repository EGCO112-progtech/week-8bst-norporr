// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
    int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void preOrder( TreeNodePtr );
void postOrder( TreeNodePtr );
void insertNode( BST *, int );
/*
void insertNode_R(TreeNodePtr * t,int value){
  if(t==NULL){
   t=new TreeNode;
	 if(t){
		t->leftPtr=NULL;
		t->rightPtr=NULL;
		t->data=value;
   }
  }
  else{
     if(t->data>=value) //left
        
     else //right
      
   }
}
*/
void insertNode( BST *b, int value ){
	 TreeNodePtr t = b->root,new_node;
	 int inserted=0;
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(!b->root)	b->root=new_node;
		else {
while(!inserted){
   if(t->data >=value){
     /* move/insert to the left*/
     if(t->leftPtr==NULL)
     {
      t->leftPtr=new_node;
      inserted=1;
     }
  	 else t = t->leftPtr;
  }
   else {
      if(t->rightPtr==NULL)
     {
      t->rightPtr=new_node;
      inserted++;
	      /* move/ insert to the right*/
    }
      else
      {
         if (t->data < value)
         {
            t=t->rightPtr;
         }
      }
	
   
  }//end while		
  }//end else;
  b->size++;
  }
}
  
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void preOrder( TreeNodePtr rootPtr )
{
   if ( rootPtr != NULL)
   {
      printf("%3d",rootPtr->data);

      preOrder( rootPtr->leftPtr);
      
      preOrder( rootPtr->rightPtr);
   }
}

void postOrder( TreeNodePtr rootPtr )
{
   if ( rootPtr != NULL)
   {
      postOrder( rootPtr->leftPtr);

      postOrder( rootPtr->rightPtr);

      printf("%3d",rootPtr->data);

   }
}

void treeOrder (TreeNodePtr treePtr, int a)
{
   if ( treePtr!=NULL )
   {
      a++;
      treeOrder (treePtr->rightPtr, a);
      for(int i=0;i<a;i++)
      {
         printf("   ");
      }
      printf("%3d", treePtr->data);
      printf("\n");
      treeOrder (treePtr->leftPtr, a);
   }
}