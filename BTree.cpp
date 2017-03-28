#include	<stdio.h>
#include	<stdlib.h>
#include	"Stacks_Queue_List.h"

typedef struct Node {
	struct Node *right;
	struct Node *left;
	int key;
} Node ;

void	InorderTraverse_NonRecursive( Node *t );
Node	*BTreeSearch( int key, Node * base, int *num );
Node	*BTreeInsert( int key, Node * base, int *num );
Node	*BTreeDelete( int key, Node * base, int *num );

void	InorderTraverse( Node *t );

int main(void)
{
	return	0;
}


void	InorderTraverse_NonRecursive( Node *t )
{
	int done = 0;
	static int StackEmpty = 0;
	initStack();
	while( !done )
	{
		while( t != NULL )
		{
			pushStack( (int)t );
			StackEmpty ++;
			t = t ->left;
		}
		if( StackEmpty )
		{
			t = (Node *)popStack();
			StackEmpty --;
			printf("%d\n", t ->key );
			t = t ->right;
		}
		else
			done = 1;
	}
}

Node	*BTreeSearch( int key, Node * base, int *num )
{
	Node	*s;
	s = base ->left;
	while( key != s ->key && s != NULL )
	{
		if( key < s ->key )
			s = s ->left;
		else
			s = s ->right;
	}
	if( s == NULL ) return	NULL;
	return	s;
}

Node	*BTreeInsert( int key, Node * base, int *num )
{
	Node	*p, *s;
	p = base;
	s = base ->left;
	while( s != NULL )
	{
		p = s ;
		if( key < s ->key )
			s = s ->left;
		else
			s = s ->right;
	}
	if( (s = (Node *)malloc(sizeof(Node))) == NULL )
		return	NULL;
	s ->key = key;
	s ->left = NULL;
	s ->right = NULL;
	if( key < p ->key || p == base )
		p ->left = s;
	else
		p ->right = s;
	(*num) ++;
	return	s;
}

Node	*BTreeDelete( int key, Node * base, int *num )
{
	Node	*parent, *son, *del, *nexth;
	parent = base;
	del = base ->left;
	while( key != del ->key && del != NULL )
	{
		parent = del;
		if( key < del ->key )
			del = del ->left;
		else
			del = del ->right;
	}
	if( del == NULL ) return	NULL;
	if( del ->right == NULL )	//  유형 1
		son = del ->left;
	else
		if( del ->right ->left == NULL )	// 유형 2
		{
			son = del ->right;
			son ->left = del ->left;
		}
		else	// 유형 3
		{
			nexth = del ->right;
			while( nexth ->left ->left != NULL ) nexth = nexth ->left;
			son = nexth ->left;
			nexth ->left = son ->right;
			son ->left = del ->left;
			son ->right = del ->right;
		}
	if( key < parent ->key || parent == base )
		parent ->left = son;
	else
		parent ->right = son;
	free( del );
	(*num) --;
	return	parent;
}