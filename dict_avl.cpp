#include "AVLTree.h"
using namespace std;


template <typename Key, typename Info>
class Dictionary
{
    AVLTree<Key, Info> dict;

public:

	Info& operator[](const Key& key)
	{
		if (dict[key] == Info())
		{
			dict.insert(key, Info());
		}
		return dict[key];
	}
	void getmost(vector<pair<string, size_t>>& result)const
	{
		dict.findBigInfo(result);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i].first << endl;
		}
	}

};

vector<pair<string, size_t>> getmostfrequent(Dictionary<string, size_t> const& dict)
{
	vector<pair<string, size_t>> result;
	dict.getmost(result);
    return vector<pair<string, size_t>>();
}


template <typename Key, typename Info>
AVLTree<Key, Info> vec2avl(const vector<pair<Key, Info>> &vec)
{
	AVLTree<Key, Info> avl;
	for (auto ele : vec)
		avl.insert(ele.first, ele.second);
	return avl;
}

int main()
{
	// TEST 1: default contructor
	{
		AVLTree<int, int> avl;
		if (!(avl.empty() && avl.count() == 0 && avl.height() == -1))
			cerr << "Error in AVLTree: Default Constructor"
			<< "\n";
	}

	// TEST 2: copy contructor && assignment operator
	{
		AVLTree<int, int> avl1 = vec2avl<int, int>({ { 1, 1 },{ 2, 2 },{ 3, 3 },{ 4, 4 } }), avl2(avl1);
		avl1.clear();
		if (!(!avl2.empty() && avl2.count() == 4 && avl2.height() == 2))
			cerr << "Error in AVLTree: Copy Constructor"
			<< "\n";
	}

	// TEST 3: move contructor
	{
		AVLTree<int, int> avl1 = vec2avl<int, int>({ { 1, 1 },{ 2, 2 },{ 3, 3 },{ 4, 4 } }), avl2(std::move(avl1));
		avl1.clear();
		if (!(!avl2.empty() && avl2.count() == 4 && avl2.height() == 2 && avl1.empty()))
			cerr << "Error in AVLTree: Move Constructor"
			<< "\n";
	}

	// TEST 4: insert method
	{
		AVLTree<int, int> avl;
		for (int i = 0; i < 10; i++)
		{
			avl.insert(i, i);
		}
		bool res1 = avl.insert(5, 5);
		if (!(!avl.empty() && avl.count() == 10 && avl.height() == 3 && !res1))
			cerr << "Error in AVLTree: Insert Method"
			<< "\n";
	}

	// TEST 5: remove method
	{
		AVLTree<int, int> avl;
		for (int i = 0; i < 10; i++)
		{
			avl.insert(i, i);
		}
		bool res1 = avl.remove(5);
		if (!(!avl.empty() && avl.count() == 9 && avl.height() == 3 && res1))
			cerr << "Error in AVLTree: Remove Method"
			<< "\n";
	}


	// TEST 7: exists, count, clear && height methods
	{
		AVLTree<int, int> avl;
		for (int i = 0; i < 100; i++)
		{
			avl.insert(i, i);
		}
		avl.print_graph();
		if (!(avl.height() == 6))
		{
			cerr << "Error in height method"
				<< "\n";
		}
		int before_avl = avl.count();
		avl.clear();
		int after_avl = avl.count();
		if (!(before_avl == 100  && after_avl == 0 ))
			cerr << "Error in clear method"
			<< "\n";
	}

	// TEST 8: output the most frequency word.
    Dictionary<string, size_t> counter;
	ifstream ifs;
	ifs.open("text.txt", ios::in);//open file
    if (ifs.is_open())
    {
        string word;
        while (ifs >> word)
            counter[word]++;
    }
    else
    {
        cout << "File open failed.\n";
    }
	vector<pair<string, size_t>> result = getmostfrequent(counter);
    return 0;


	// TEST 9: display
	
}

