#include <iostream>
#include <string.h>
#include <queue>
using namespace std;



///----------CLASS 1-----------
class Node
{
private:
    int info;
    Node *left;
    Node *right;
public:
    Node();
    Node(int);
    Node(const Node & x);
    ~Node();
    int get_info();
    Node* get_left();
    Node* get_right();
    void set_info(int);
    void set_left(Node*);
    void set_right(Node*);
    Node operator=(Node x);
    friend ostream &operator << (ostream &output, Node x);
    friend istream &operator >> (istream &input, Node &x);
  //  friend class Tree;
};
///-----------CONSTRUCTORS & DESTRUCTOR-----------
/*Node::Node()
{
    info = 0;
    st = NULL;
    dr = NULL;
    cout << endl << "Initialization constructor without parameters Node." << endl;
}*/
Node::Node(int x = 10)
{
    info = x;
    right = NULL;
    left = NULL;
    cout << endl << "Initialization constructor with parameters Node." << endl;
}
Node::Node(const Node &x)
{
    info = x.info;
    left = x.left;
    right = x.right;
    cout << endl << "Copy constructor Node." << endl;
}
Node::~Node()
{
    cout << endl << "Destructor Node." << endl;
}
///----------OPERATORS----------
Node Node::operator=(Node x)
{
    info = x.info;
    left = x.left;
    right = x.right;
    return *this;
}
ostream &operator << (ostream &output, Node x)
{
    Node y = x;
    output << endl << y.info;
    return output;
}
istream &operator >> (istream &input, Node &x)
{
    cout << endl << "Info:";
    input >> x.info;
    return input;
}
///-------METHODS------
int Node::get_info()
{
    return info;
}
Node* Node::get_left()
{
    return left;
}
Node* Node::get_right()
{
    return right;
}
void Node::set_info(int x)
{
    info = x;
}
void Node::set_left(Node* x)
{
    left = x;
}
void Node::set_right(Node* x)
{
    right = x;
}



///----------CLASS 2-----------
class Red_black_node:virtual public Node
{
private:
    char color[100];
public:
    Red_black_node();
    Red_black_node(int x, char y[]);
    Red_black_node(const Red_black_node & x);
    ~Red_black_node();
    int get_info();
    Red_black_node* get_left();
    Red_black_node* get_right();
    void set_info(int);
    void set_left(Red_black_node*);
    void set_right(Red_black_node*);
    Red_black_node operator=(Red_black_node y);
    friend ostream &operator << (ostream &output, Red_black_node x);
    friend istream &operator >> (istream &input, Red_black_node &x);
};
///------------CONSTRUCTORI & DESTRUCTOR-------------
/*Red_black_node::Red_black_node()
{
    info = 0;
    st = NULL;
    dr = NULL;
    color[0] = '\0';
    cout << endl << "Constructor de initializare fara parametri Red_black_node". << endl;
}*/
Red_black_node::Red_black_node(int x = 10, char y[] = "black"):Node(x)
{
    strcpy(color, y);
    cout << endl << "Initialization constructor with parameters Red_black_node." << endl;
}
Red_black_node::Red_black_node(const Red_black_node &x):Node(x)
{
    int n = strlen(x.color);
    for(int i = 0; i < n; i++)
        color[i] = x.color[i];
    cout << endl << "Copy constructor Red_black_node." << endl;
}
Red_black_node::~Red_black_node()
{
    cout << endl << "Destructor Red_black_node." << endl;
}
///---------OPERATORS----------
Red_black_node Red_black_node::operator=(Red_black_node x)
{
    set_info(x.get_info());
    set_left(x.get_left());
    set_right(x.get_right());
    strcpy(color, x.color);
    return *this;
}
ostream &operator << (ostream &output, Red_black_node x)
{
    Red_black_node z = x;
    output << endl << z.get_info() << endl;
    int n = strlen(x.color);
    for(int i = 0; i < n; i++)
        output << z.color[i];
    return output;
}
istream &operator >> (istream &input, Red_black_node &x)
{
    cout << endl << "Info: ";
    int a;
    input >> a;
    x.set_info(a);
    cout << endl << "Length word color: ";
    int n;
    input >> n;
    int i;
    for(i = 0; i < n; i++)
        input >> x.color[i];
    x.color[i] = '\0';
    return input;
}
///-------METHODS-------
int Red_black_node::get_info()
{
    return get_info();
}
Red_black_node* Red_black_node::get_left()
{
    return get_left();
}
Red_black_node* Red_black_node::get_right()
{
    return get_right();
}
void Red_black_node::set_info(int x)
{
    set_info(x);
}
void Red_black_node::set_left(Red_black_node* x)
{
    set_left(x);
}
void Red_black_node::set_right(Red_black_node* x)
{
    set_right(x);
}


///-----------CLASS 3-----------
class Tree
{
private:
    int nr_nodes;
public:
    Tree();
    Tree(Tree &);
    virtual ~Tree();
    virtual Nod* DeleteTree(Node*) = 0;
    virtual Nod* Minim(Node*) = 0;
    virtual Nod* create_node(int) = 0;
    virtual void Insert(int x) = 0;
    virtual void Insert_nod(int, Node* &) = 0;
    virtual void delete_nod(int, Node* &) = 0;
    virtual void SRD(int info, Node* left, Node* right) = 0;
    virtual Nod* get_root() = 0;
};
///------------CONSTRUCTORS & DESTRUCTOR-------------
Tree::Tree()
{
    nr_nodes = -1;
    cout << endl << "Initialization constructor Tree." << endl;
}
Tree::Tree(Tree & tree)
{
    cout << endl << "Copy constructor Tree." << endl;
}
Tree::~Tree()
{
//    Nod* a = get_root();
//    DeleteTree(a);
    cout << endl << "Destructor Tree." << endl;
}



///----------CLASS 4------------
class ABC:virtual public Tree
{
private:
      Node* root;
public:
    ABC();
    ABC(ABC &);
    ~ABC();
    Node* DeleteTree(Nod*);
    Node* Minim(Nod*);
    Node* create_node(int);
    void Insert(int x);
    void Insert_node(int, Node* &);
    void delete_node(int, Node* &);
    void SRD(int info, Node* left, Node* right);
    void Copy(Node*);
    Node* get_root();
    const ABC& operator=(const ABC&);
    friend istream &operator >> (istream &in, ABC & arbore);
    friend ostream &operator << (ostream &out, ABC & arbore);
};
///-------------METHODS------------
Nod* ABC::Minim(Node* root)
{
    if (root->get_left() == NULL)
        return root;
    else
        return Minim(root->get_left());
}
Nod* ABC::create_node(int x)
{
    Nod* temp = new Node(x);
    temp->set_info(x);
    temp->set_left(NULL);
    temp->set_right(NULL);
    return temp;
}
Nod* ABC:: DeleteTree(Node* root)
{
    if(root == NULL)
        return root;
    else
    {
        root->set_left(DeleteTree(root->get_left()));
        root->set_right(DeleteTree(root->get_right()));
    }
    delete root;
}
void ABC::Insert(int x)
{
    Insert_nod(x, root);
}
void ABC::Insert_node(int x, Node* & root)
{
    if (root == NULL)
        root = create_node(x);
    else
    {
        if (x < root->get_info())
        {
            Node* a = root->get_left();
            Insert_node(x,  a); //we go in the left subtree
        }
        else if (x > root->get_info())
        {

            Node* a = root->get_right();
            Insert_node(x, a); //we go in the right subtree
        }
        else //if x is equal with root->info => it is already in the tree, so we won't insert it
            cout << endl << "!!!!!!!!!  The node was already in the tree  !!!!!!!!" << endl;
    }
}
void ABC::delete_node(int x, Nod* & root)
{
    if (root == NULL)  //we don't have what to delete from the tree
        return;
    else if (root->get_info() < x)
    {
        Node* a = root->get_right();
        delete_node(x, a); //we go in the right subtree
    }
    else if (root->get_info() > x)
        {
            Node* a = root->get_left();
            delete_node(x, a);  //we go in the left subtree
        }
    else if (root->get_info() == x) //if we found the node that we have to delete
    {
        if (root->get_left() == NULL && root->get_right() != NULL) //if it has only the right son
            root = root->get_right();
        else if (root->get_left() != NULL && root->get_right() == NULL) //if it has only the left son
            root = root->get_left();
        else if (root->get_left() == NULL && root->get_right() == NULL) //if it has no son (it's leaf)
               root = NULL;
        else if (root->get_left() != NULL && root->get_right() != NULL) //if it has both sons
        {
            Node* temp = Minim(root->get_right()); //retain the minimum from the right subtree
            root->set_info(temp->get_info());
            Node* a = root->get_right();
            delete_node(temp->get_info(), a); //delete the node
        }
    }
}
void ABC::SRD(int info, Node* st, Node* dr)
{
    if (root != NULL)
    {
        SRD(left->get_info(), left->get_left(), left->get_right());
        cout << info << "  ";
        SRD(right->get_info(), right->get_left(), right->get_right());
    }
}
void ABC::Copy(Node* x)
{
    if(x)
    {
        Insert(x->get_info());
        Copy(x->get_left());
        Copy(x->get_right());
    }
}
Node* ABC::get_root()
{
    return root;
}
///----------CONSTRUCTORS & DESTRUCTOR-------------
ABC::ABC()
{
    root = NULL;
    cout << endl << "Initialization constructor binary search tree." << endl;
}
ABC::ABC(ABC & tree)
{
    Copy(root);
    //SAU   dfs + creare noduri pe parcurs
    cout << endl << "Copy constructor Binary search tree." << endl;
}
ABC::~ABC()
{
    DeleteTree(root);
    cout << endl << "Destructor Binary search tree." << endl;
}
///-----------OPERATORS-------------
const ABC& ABC:: operator=(const ABC& tree)
{
        DeleteTree(root);
        root = NULL;
        Copy(tree.root);
        return *this;
}
istream& operator>>(istream& in, ABC& tree)
{
    int x;
    in >> x;
    tree.Insert(x);
    return in;
}
ostream& operator<<(ostream& out, ABC& tree)
{
    Node* a = tree.get_root();
    tree.SRD(a->get_info(), a->get_left(), a->get_right());
    return out;
}


/*
///-----------CLASS 5------------
class Bicolor_tree:virtual public Arbore
{
private:
    Red_black_node *root;
public:
    Bicolor_tree();
    Bicolor_tree(Bicolor_tree & tree);
    ~Bicolor_tree();
    Bicolor_tree operator=(Bicolor_tree tree);
    friend istream& operator>>(istream& in, ABC& tree);
    friend ostream& operator<<(ostream& out, ABC tree);
};
///----------CONSTRUCTORS & DESTRUCTOR------------
Bicolor_tree::Bicolor_tree()
{
    root = NULL;
    cout << endl << "Constructor initializare Arbore bicolor." << endl;
}
Bicolor_tree::Bicolor_tree(Bicolor_tree & arbore)
{

}
Bicolor_tree::~Bicolor_tree()
{
    DeleteTree(root);
    cout << endl << "Destructor Arbore bicolor." << endl;
}
///---------METHODS---------
int Bicolor_tree::height(Nod* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int height_left = height(root->st);
        int height_right = height(root->dr);

        if (height_left < height_right)
            return height_right + 1;
        else
            return height_left + 1;
    }
}
*/
int main()
{
    ///---------------READ DATA-----------------
    ABC *tree = new ABC;
    int n, i, x;
    cout << endl << "Number of nodes: " << endl;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cout << endl << "Enter node value: " << endl;
        cin >> x;
        tree->Insert(x);
    }
    cout << "tree:   ";
    cout << tree;
    return 0;
}
