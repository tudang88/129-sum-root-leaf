#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "BinaryTree.h"

using namespace std;

/**
 * helper for printout
*/
static void printOutput(vector<vector<int>>& allLayers) {
    cout<<"Depth: "<< allLayers.size() << endl;
    cout<<"[";
    for (auto layer : allLayers) {
        cout<<"[";
        for (int idex = 0; idex < layer.size(); idex++) {
            cout<< layer.at(idex);
            if (idex != (layer.size() -1)) cout << ",";
        }
        cout<<"]";
    }
    cout<<"]\n";
}

/**
 * compare vector
*/
static bool compareVector(vector<vector<int>>& vector1, vector<vector<int>>& vector2) {
    if (vector1.size() != vector2.size()) return false;
    for (int layer = 0; layer < vector1.size(); layer++) {
        for (int nodeIdx; nodeIdx < vector1.at(layer).size(); nodeIdx++) {
            if (vector1.at(layer).at(nodeIdx) != vector2.at(layer).at(nodeIdx)) return false;
        }
    }
    return true;
}

static void test() {
  /**
   * test case 1
  */
  {
      cout<<"===============TEST 1 START================="<<endl;
      cout<<"Tree:root = [1,2,3]\n";
      cout<<"Expected: 25\n";
      int expected = 25;
      TreeNode *root = new TreeNode(1);
      TreeNode *l10 = new TreeNode(2);
      TreeNode *l11 = new TreeNode(3);
    //   TreeNode *l22 = new TreeNode(15);
    //   TreeNode *l23 = new TreeNode(17);
      root->left = l10;
      root->right = l11;
    //   l11->left = l22;
    //   l11->right = l23;

      // confirm solution
      Solution solution;
      auto result = solution.sumNumbers(root);
      cout<< "RESULT: "<< result<<endl;
      cout<< (result == expected? "PASS": "FAIL") << endl;
      delete root;
      delete l10;
      delete l11;
    //   delete l22;
    //   delete l23;
  }

/**
   * test case 2
  */
  {
      cout<<"===============TEST 2 START================="<<endl;
      cout<<"Tree:root = [4,9,0,5,1]\n";
      int expected = 495 + 491 + 40;
      cout<<"Expected: " << expected << endl;
      TreeNode *root = new TreeNode(4);
      TreeNode *l10 = new TreeNode(9);
      TreeNode *l11 = new TreeNode(0);
      TreeNode *l20 = new TreeNode(5);
      TreeNode *l21 = new TreeNode(1);
      root->left = l10;
      root->right = l11;
      l10->left = l20;
      l10->right = l21;
      // confirm solution
      Solution solution;
      auto result = solution.sumNumbers(root);
      cout<< "RESULT: "<< result<<endl;
      cout<< (result == expected? "PASS": "FAIL") << endl;
      delete root;
      delete l10;
      delete l11;
      delete l20;
      delete l21;
  }

  /**
   * test case 3
  */
  {
      cout<<"===============TEST 3 START================="<<endl;
      cout<<"Tree:root = []\n";
      cout<<"Expected: 0\n";
    //   vector<vector<int>> expected = {};
      TreeNode *root = nullptr;
      // confirm solution
      Solution solution;
      auto result = solution.sumNumbers(root);
    //   printOutput(result);
      cout<< ((result == 0)? "PASS": "FAIL") << endl;
  }
}
/**
 * main function
*/
int main(int argc, const char** argv) {
  test();
  return 0;
}


