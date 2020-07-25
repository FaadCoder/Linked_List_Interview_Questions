#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
#define take_input freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
class linked_list{
public:
	ll data;
	linked_list *next;
	linked_list()
	{
		this->next=NULL;
	}
	linked_list(ll data)
	{
		this->data=data;
		this->next=NULL;
	}
	linked_list *add(ll data,linked_list *head)
	{
		// CASE:1
		if(head==NULL)
		{
			linked_list *temp=new linked_list(data);
			head=temp;
		}
		else
		{
			// CASE:2
			linked_list *temp=head;
			while(temp->next!=NULL)
			temp=temp->next;	
			temp->next=new linked_list(data);
		}
		return head;
	}
	void print(linked_list *head)
	{
		auto temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	ll middle_element(linked_list *head)
	{
		auto sp=head,fp=head;
		while(fp!=NULL and fp->next!=NULL)
		{
			sp=sp->next;
			fp=fp->next->next;
		}
		return sp->data;
	}
	linked_list *delete_middle(linked_list *head)
	{
		auto sp=head,fp=head;
		auto pre=sp;
		while(fp!=NULL and fp->next!=NULL)
		{
			pre=sp;
			sp=sp->next;
			fp=fp->next->next;
		}
		pre->next=sp->next;
		delete sp;
		return head;
	}
	linked_list *delete_linked_list(auto head)
	{
		auto pre=head;
		head=head->next;
		if(head==NULL)
		{
			delete pre;
		}
		while(head!=NULL)
		{
			delete pre;
			pre=head;
			head=head->next;
		}
		return head;
	}
	void print_reverse(auto head)
	{
		if(head==NULL)
			return;
		print_reverse(head->next);
		cout<<head->data<<" ";
	}
	auto reverse_linked_list(auto head)
	{
		linked_list *cur=head,*next=head,*pre=NULL;
		while(cur)
		{
			next=cur->next;
			cur->next=pre;
			pre=cur;
			cur=next;
		}
		return pre;
	}
	bool is_palindrome(auto &left,auto right)
	{
		if(right==NULL)
			return true;
		bool first=is_palindrome(left,right->next);
		if(first==false)
			return false;
		bool second=(right->data==left->data);
		left=left->next;
		return second;
	}
	auto remove_duplicate_sorted(auto head)
	{
		auto cur=head;
		while(cur->next!=NULL)
		{
			if(cur->data==cur->next->data)
			{
				auto temp=cur->next;
				cur->next=temp->next;
				delete temp;
			}
			else
				cur=cur->next;
			
		}
		return head;
	}
	auto remove_duplicate_unsorted(auto head)
	{
		set<ll> vis;
		auto cur=head,pre=cur;
		while(cur)
		{
			if(vis.count(cur->data))
			{
				pre->next=cur->next;
				delete cur;
			}
			else
			{
				vis.insert(cur->data);
				pre=cur;
			}
			cur=pre->next;
		}
		return head;
	}
	bool detect_loop(auto head)
	{
		auto sp=head,fp=head;
		while(fp and fp->next)
		{
			sp=sp->next;
			fp=fp->next->next;
			if(sp==fp)
				return true;
		}
		return false;
	}
	auto remove_loop(auto head)
	{
		auto sp=head,fp=head;
		while(fp and fp->next)
		{
			sp=sp->next;
			fp=fp->next->next;
			if(sp==fp)
				break;
		}
		if(sp==fp)
		{
			sp=head;
			while(sp->next!=fp->next)
			{
				sp=sp->next;
				fp=fp->next;
			}
			fp->next=NULL;
		}
		return head;
	}
	ll intersection_point(auto head1,auto head2)
	{
		auto cur1=head1,cur2=head2;
		while(cur1!=cur2)
		{
			if(cur1==NULL)
				cur1=head2;
			else
				cur1=cur1->next;
			if(cur2==NULL)
				cur2=head1;
			else
				cur2=cur2->next;
		}
		return cur1->data;
	}
	auto odd_even(auto head)
	{
		auto o=head,e=head->next,temp=e;
		while(e!=NULL and e->next!=NULL)
		{
			o->next=e->next;
			o=o->next;
			e->next=o->next;
			e=e->next;
		}
		o->next=temp;
		return head;
	}
	auto merge(auto h1,auto h2)
	{
		if(h1==NULL or h2==NULL)
		{
			return (h1==NULL)?h2:h1;
		}
		if(h1->data<h2->data)
		{
			h1->next=merge(h1->next,h2);
			return h1;
		}
		else
		{
			h2->next=merge(h1,h2->next);
			return h2;
		}

	}
	auto mergesort(auto head)
	{
		if(head==NULL or head->next==NULL)
			return head;
		auto sp=head,fp=head,pre=sp;
		while(fp and fp->next)
		{
			pre=sp;
			sp=sp->next;
			fp=fp->next->next;
		}
		pre->next=NULL;
		auto h1=mergesort(head);
		auto h2=mergesort(sp);
		return merge(h1,h2);
	}
};

int main()
{
	// take_input;
	fast;
	linked_list *head1=NULL,*head2=NULL;
	head1=head1->add(6,head1);
	head1=head1->add(2,head1);
	head1=head1->add(5,head1);
	head1=head1->add(4,head1);
	head1=head1->add(5,head1);
	head1=head1->add(1,head1);
	
	head1=head1->mergesort(head1);
	head1->print(head1);
}