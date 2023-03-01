#include <cstdio>
#include <cstdlib>
#include <ctime>

#define num 4 //阶数，自定义

typedef int keyType; //数据类型

typedef struct BTNode //节点
{
    int keyNum;                    //关键字数
    keyType key[num];              //关键字数组
    struct BTNode *child[num + 1]; //子节点数组
    struct BTNode *parent;         //父节点
    bool isLeaf;                   //是否是叶节点
} BTNode, *BTree;

BTree BTree_init() //初始化节点
{
    BTree root = (BTree) malloc(sizeof(BTNode));
    root->keyNum = 0;
    root->parent = NULL;
    root->isLeaf = true;
    return root;
}

static bool is_full(BTree node) //判断节点node是否满
{
    if (node->keyNum < num) {
        return false;
    }
    return true;
}

static int insert_key(BTree node, keyType key) //向节点node插入key，返回插入位置
{
    if (node->keyNum == 0) {
        node->key[0] = key;
        node->keyNum++;
        return 0;
    } else if (key >= node->key[node->keyNum - 1]) {
        node->key[node->keyNum] = key;
        node->keyNum++;
        return node->keyNum - 1;
    } else {
        int index;
        for (int i = 0; i < node->keyNum; i++) {
            if (key < node->key[i]) {
                keyType temp = node->key[i];
                node->key[i] = key;
                node->keyNum++;
                index = i;
                for (int j = i + 1; j < node->keyNum; j++) {
                    key = node->key[j];
                    node->key[j] = temp;
                    temp = key;
                }
                break;
            }
        }
        return index;
    }
}

//向父节点parent插入key，new_node是分裂出的子节点
static void insert_parent(BTree *root, BTree parent, BTree node, BTree new_node, keyType key) {
    int index = insert_key(parent, key);
    parent->child[index] = node;
    node->parent = parent;
    BTree temp = parent->child[index + 1];
    parent->child[index + 1] = new_node;
    new_node->parent = parent;

    for (int i = parent->keyNum; i >= index + 2; i--) {
        if (i == index + 2) {
            parent->child[i] = temp;
            break;
        }
        parent->child[i] = parent->child[i - 1];
    }

    if (!is_full(parent)) {
        return;
    }

    int split = parent->keyNum / 2; //节点满的分裂位置
    key = parent->key[split];
    BTree new_parent = BTree_init(); //分裂出的节点
    new_parent->keyNum = parent->keyNum - split - 1;
    new_parent->isLeaf = false;

    for (int i = 0; i < new_parent->keyNum; i++) {
        new_parent->child[i] = parent->child[split + i + 1];
        new_parent->child[i]->parent = new_parent;
        new_parent->key[i] = parent->key[split + i + 1];
    }
    new_parent->child[new_parent->keyNum] = parent->child[parent->keyNum];
    new_parent->child[new_parent->keyNum]->parent = new_parent;
    parent->keyNum = split;

    if (!parent->parent) //若分裂的节点是根节点，则要新建一个根节点
    {
        BTree new_root = BTree_init();
        new_root->isLeaf = false;
        insert_parent(root, new_root, parent, new_parent, key);
        *root = new_root;
    } else {
        insert_parent(root, parent->parent, parent, new_parent, key);
    }
}

static void split_leaf(BTree *root, BTree leaf) //分裂叶节点leaf
{
    int split = leaf->keyNum / 2;
    int key = leaf->key[split];
    int total = leaf->keyNum;
    BTree new_leaf = BTree_init(); //分裂出的叶节点
    leaf->keyNum = split;
    new_leaf->keyNum = total - split;

    for (int i = 0; i < new_leaf->keyNum; i++) {
        new_leaf->key[i] = leaf->key[split + i];
    }

    if (!leaf->parent) //若分裂的叶节点是根节点，则要新建一个根节点
    {
        BTree new_root = BTree_init();
        new_root->isLeaf = false;
        insert_parent(root, new_root, leaf, new_leaf, key);
        *root = new_root;
    } else {
        insert_parent(root, leaf->parent, leaf, new_leaf, key);
    }
}

static void insert_leaf(BTree *root, BTree leaf, keyType key) //向叶节点leaf插入key
{
    insert_key(leaf, key);
    if (!is_full(leaf)) {
        return;
    }
    split_leaf(root, leaf); //叶节点已满，则分裂
}

static void BTree_insert(BTree *root, keyType key) //向树中插入key，root是根节点的指针
{
    if (*root == NULL) //若未创建根节点，则新建
    {
        *root = BTree_init();
    }

    BTree tree = *root;
    while (!tree->isLeaf) //由二叉搜索树性质找到要插入的叶节点
    {
        if (key >= tree->key[tree->keyNum - 1]) {
            tree = tree->child[tree->keyNum];
            continue;
        }
        for (int i = 0; i < tree->keyNum; i++) {
            if (key < tree->key[i]) {
                tree = tree->child[i];
                break;
            }
        }
    }

    insert_leaf(root, tree, key);
}

void print_tree(BTree tree) //打印以tree为根的子树
{
    if (tree->isLeaf) {
        printf("leaf:");
        for (int i = 0; i < tree->keyNum; i++) {
            printf("%d ", tree->key[i]);
        }
        printf("\n");
        return;
    }

    printf("node:");
    for (int i = 0; i < tree->keyNum; i++) {
        printf("%d ", tree->key[i]);
    }
    printf("\n");

    for (int i = 0; i <= tree->keyNum; i++) {
        print_tree(tree->child[i]);
    }
}

void TestModule() {
    BTree root = NULL;
    srand(time(NULL)); //随机数生成
    printf("insert:");
    for (int i = 0; i < 20; i++) {
        int insert = rand() % 50;
        printf("%d ", insert);
        BTree_insert(&root, insert);
    }
    printf("\n\nprint:\n");
    print_tree(root);
}
