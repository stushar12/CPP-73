int isroot(Node *root)
{
    if(root==NULL)
    return 0;
    int lh=isroot(root->left);
    if(lh<0)
    return -1;
    int rh=isroot(root->right);
    if(rh<0)
    return -1;
    if(abs(lh-rh)>1)
    {
        return -1;
    }
    else
    return max(lh,rh)+1;
}
bool isBalanced(Node *root)
{
int a=isroot(root);
if(a==-1)
return false;
else
return true;
}