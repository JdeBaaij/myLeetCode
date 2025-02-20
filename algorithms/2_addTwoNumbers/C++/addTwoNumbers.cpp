#include <list>
#include <iostream>

// Definition for singly-linked list.struct ListNode
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
My original aproach:


Due to the numbers being backwards my initial instinct was to use recursion to read both lists

This approach works for small numbers but runs into an issue wiht large numbers

*/

// class Solution
// {
// 	unsigned long _l1total = 0;
// 	unsigned long _l2total = 0;

// public:
// 	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// 	{
// 		// recursion to go to end of the list
// 		recursionl1(l1);
// 		recursionl2(l2);

// 		std::cout << "_l1total: " << _l1total << std::endl;
// 		std::cout << "_l2total: " << _l2total << std::endl;
// 		unsigned mult = _l1total + _l2total;
// 		std::cout << "mult  " << mult << std::endl;

// 		ListNode *output = new ListNode();
// 		int last_digit = mult % 10;
// 		mult = mult / 10;
// 		output->val = last_digit;

// 		ListNode *last;
// 		last = output;
// 		while (mult != 0)
// 		{
// 			ListNode *nxt = new ListNode();
// 			last->next = nxt;
// 			last = nxt;
// 			int last_digit = mult % 10;
// 			mult = mult / 10;
// 			last->val = last_digit;
// 		}
// 		return (output);
// 	}
// 	void recursionl1(ListNode *l1)
// 	{
// 		if (l1->next != nullptr)
// 		{
// 			recursionl1(l1->next);
// 		}
// 		_l1total = _l1total * 10;
// 		_l1total += l1->val;
// 	}
// 	void recursionl2(ListNode *l2)
// 	{
// 		if (l2->next != nullptr)
// 		{
// 			recursionl2(l2->next);
// 		}
// 		_l2total = _l2total * 10;
// 		_l2total += l2->val;
// 	}
// };

/*
New approach: using addition one number at the time:

Here I read both lists at the same time, due to the nature of addition this is a fairly easy way of making the list

*/

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *start = new ListNode(0); // dummy head
		ListNode *current = start;
		int carry = 0;

		while (l1 != nullptr || l2 != nullptr)
		{
			int n1 = 0;
			int n2 = 0;
			if (l1 != nullptr)
			{
				n1 = l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				n2 = l2->val;
				l2 = l2->next;
			}
			int sum = carry + n1 + n2;
			carry = sum / 10;
			current->next = new ListNode(sum % 10);
			current = current->next;
		}
		if (carry > 0)
		{
			current->next = new ListNode(carry);
		}
		ListNode *output = start->next;
		delete start;
		return output;
	}
};

int main(void)
{
	// l1
	ListNode *l1 = new ListNode(1);
	ListNode *current = l1;
	for (int i = 0; i < 29; ++i)
	{
		current->next = new ListNode(0);
		current = current->next;
	}
	current->next = new ListNode(1);

	// l2
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	Solution sol;

	ListNode *output = sol.addTwoNumbers(l1, l2);

	while (output != nullptr)
	{
		std::cout << output->val << std::endl;
		output = output->next;
	}

	// cleanup
	while (l1 != nullptr)
	{
		ListNode *temp = l1;
		l1 = l1->next;
		delete temp;
	}
	while (l2 != nullptr)
	{
		ListNode *temp = l2;
		l2 = l2->next;
		delete temp;
	}
	while (output != nullptr)
	{
		ListNode *temp = output;
		output = output->next;
		delete temp;
	}
}