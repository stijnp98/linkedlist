#include <gtest/gtest.h>
#include "linked_list.h"

/***************************************************************************/
TEST(addtest,normal) {
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	EXPECT_EQ(1,i);

	i=add_to_list(head,str2);
	EXPECT_EQ(2,i);

	i=add_to_list(head,str3);
	EXPECT_EQ(3,i);

	i=add_to_list(head,str4);
	EXPECT_EQ(4,i);

	i=add_to_list(head,str5);
	EXPECT_EQ(5,i);

	i=add_to_list(head,str6);
	EXPECT_EQ(6,i);

}

/***************************************************************************/
TEST(search,normal)
{
	char str[15]="List Start";
	char str1[15]="second";
	char str2[15]="third";
	char res[15]="third";
	int i;

	 linked_list *found = (struct linked_list*) malloc(sizeof(linked_list));
	 linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));;

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	EXPECT_EQ(1,i);

    i=add_to_list(head,str2);
	EXPECT_EQ(2,i);

	found=search_from_list(head,res);
	EXPECT_EQ(found->index,2);
	EXPECT_STREQ(str2,found->data);
}
/***************************************************************************/
TEST(search,not_found)
{
	char str[15]="List Start";

	linked_list *found;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	found=search_from_list(head,(char *)"third");

	EXPECT_EQ((int *)found,(int *)NULL);
}
/***************************************************************************/
TEST(display_list,empty)
{
	int result;
	char str[15]="List Start";

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	display_list(head);

}
/***************************************************************************/
TEST(display_item,add_to_list)
{
	int result;
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *find;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	display_item(find);
	EXPECT_EQ(head->next->index,1);
	EXPECT_EQ(i,1);
	EXPECT_STREQ(head->next->data,str1);

	i=add_to_list(head,str2);
	display_list(head);
	EXPECT_EQ(head->next->next->index,2);
	EXPECT_EQ(i,2);
	EXPECT_STREQ(head->next->next->data,str2);

	i=add_to_list(head,str3);
	display_list(head);
	EXPECT_EQ(head->next->next->next->index,3);
	EXPECT_EQ(i,3);
	EXPECT_STREQ(head->next->next->next->data,str3);

	i=add_to_list(head,str4);
	display_list(head);
	EXPECT_EQ(head->next->next->next->next->index,4);
	EXPECT_EQ(i,4);
	EXPECT_STREQ(head->next->next->next->next->data,str4);

	i=add_to_list(head,str5);
	display_list(head);
	EXPECT_EQ(head->next->next->next->next->next->index,5);
	EXPECT_EQ(i,5);
	EXPECT_STREQ(head->next->next->next->next->next->data,str5);

	i=add_to_list(head,str6);
	display_list(head);
	EXPECT_EQ(head->next->next->next->next->next->next->index,6);
	EXPECT_EQ(i,6);
	EXPECT_STREQ(head->next->next->next->next->next->next->data,str6);

}
/***************************************************************************/
TEST(display_list,normal)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;


	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;



	i=add_to_list(head,str1);
	i=add_to_list(head,str2);
	i=add_to_list(head,str3);
	i=add_to_list(head,str4);
	i=add_to_list(head,str5);
	i=add_to_list(head,str6);


	display_list(head);
}
/***************************************************************************/
TEST(strcmp,normal)
{
	char str[15]="abba";
	char str1[10]="bbaa";
	char str2[10]="baaa";
	char str3[10]="aabb";
	char str4[10]="cccc";

	EXPECT_EQ(strcomp(str1,str2),0);
	EXPECT_EQ(strcomp(str2,str1),2);

}

TEST(sort,normal)
{
	char str[15]="abba";
	char str1[10]="bbaa";
	char str2[10]="baaa";
	char str3[10]="aabb";
	char str4[10]="cccc";
	char str5[10]="caba";
	char str6[10]="caab";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	i=add_to_list(head,str2);
	i=add_to_list(head,str3);
	i=add_to_list(head,str4);
	i=add_to_list(head,str5);
	i=add_to_list(head,str6);

	EXPECT_STREQ(search_for_index(head,0)->data,"abba");
	EXPECT_STREQ(search_for_index(head,1)->data,"bbaa");

	sort_list(head);

	display_list(head);

	EXPECT_STREQ(head->data,"aabb");
	EXPECT_STREQ(head->next->data,"abba");
	EXPECT_STREQ(head->next->next->data,"baaa");
	EXPECT_STREQ(head->next->next->next->data,"bbaa");
	EXPECT_STREQ(head->next->next->next->next->data,"caab");
	EXPECT_STREQ(head->next->next->next->next->next->data,"caba");
	EXPECT_STREQ(head->next->next->next->next->next->next->data,"cccc");

}

TEST(sort,special)
{
	char str[15]="abba";
	char str1[10]="Bbaa";
	char str2[10]="baaa";
	char str3[10]="521";
	char str4[10]="102";
	char str5[10]="ab";
	char str6[10]="caa";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	i=add_to_list(head,str2);
	i=add_to_list(head,str3);
	i=add_to_list(head,str4);
	i=add_to_list(head,str5);
	i=add_to_list(head,str6);

	EXPECT_STREQ(search_for_index(head,0)->data,"abba");
	EXPECT_STREQ(search_for_index(head,1)->data,"Bbaa");

	sort_list(head);

	display_list(head);

	EXPECT_STREQ(head->data,"102");
	EXPECT_STREQ(head->next->data,"521");
	EXPECT_STREQ(head->next->next->data,"Bbaa");
	EXPECT_STREQ(head->next->next->next->data,"ab");
	EXPECT_STREQ(head->next->next->next->next->data,"abba");
	EXPECT_STREQ(head->next->next->next->next->next->data,"baaa");
	EXPECT_STREQ(head->next->next->next->next->next->next->data,"caa");

}

/***************************************************************************/
TEST(delete,normal)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;


	i=add_to_list(head,str1);
	i=add_to_list(head,str2);
	i=add_to_list(head,str3);
	i=add_to_list(head,str4);
	i=add_to_list(head,str5);
	i=add_to_list(head,str6);

	EXPECT_EQ(delete_from_list(head,2),6);

}
/***************************************************************************/
TEST(delete,multi) {
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;
	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	i=add_to_list(head,str2);
	i=add_to_list(head,str3);
	i=add_to_list(head,str4);
	i=add_to_list(head,str5);
	i=add_to_list(head,str6);

	for(i=0; i<40; i++)
	add_to_list(head,str1);

	EXPECT_EQ(delete_from_list(head,12),46);
	EXPECT_EQ(delete_from_list(head,22),45);
	EXPECT_EQ(delete_from_list(head,25),44);
	EXPECT_EQ(delete_from_list(head,32),43);
	EXPECT_EQ(delete_from_list(head,38),42);

	EXPECT_EQ(delete_from_list(head,380),-1);
}
/***************************************************************************/
TEST(empty,normal) {
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	i=add_to_list(head,str2);
	i=add_to_list(head,str3);
	i=add_to_list(head,str4);
	i=add_to_list(head,str5);
	i=add_to_list(head,str6);
	EXPECT_EQ(empty_list(head),7);
	EXPECT_STREQ(head->data,"");
	display_list(head);
}
/***************************************************************************
                            replace function
***************************************************************************/
TEST(replace,normal) {
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	i=add_to_list(head,str2);
	i=add_to_list(head,str3);
	i=add_to_list(head,str4);
	i=add_to_list(head,str5);
	i=add_to_list(head,str6);
	EXPECT_STREQ(head->next->next->data,"first");
	EXPECT_STREQ(head->next->next->next->next->data,"third");
	EXPECT_STREQ(head->next->data,"zero");
	EXPECT_STREQ(head->next->next->next->next->next->data,"fourth");
	//swap first with third in the list
	EXPECT_EQ(swap_items(head->next->next, head->next->next->next->next),0);
	//swap zero with fourth in the list
	EXPECT_EQ(swap_items(head->next, head->next->next->next->next->next),0);
	EXPECT_STREQ(head->next->next->data,"third");
	EXPECT_STREQ(head->next->next->next->next->data,"first");
	EXPECT_STREQ(head->next->data,"fourth");
	EXPECT_STREQ(head->next->next->next->next->next->data,"zero");
	display_list(head);
}

TEST(replace,error) {
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i = 0;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	i=add_to_list(head,str1);
	i=add_to_list(head,str2);
	i=add_to_list(head,str3);
	i=add_to_list(head,str4);
	i=add_to_list(head,str5);
	i=add_to_list(head,str6);
	EXPECT_STREQ(head->next->next->data,"first");
	EXPECT_STREQ(head->next->next->next->next->data,"third");
	//swap first with NULL in the list
	EXPECT_EQ(swap_items(head->next->next, NULL),-1);
	//swap first with NULL in the list
	EXPECT_EQ(swap_items(head->next->next->next->next, NULL),-1);
	EXPECT_STREQ(head->next->next->data,"first");
	EXPECT_STREQ(head->next->next->next->next->data,"third");
	display_list(head);
}

/************************************************************************************
 *                                  Status function
 ***********************************************************************************/

TEST(status,normal)
{
	char str[15]="List Start";
	char str1[10]="zero";
	char str2[10]="first";
	char str3[10]="second";
	char str4[10]="third";
	char str5[10]="fourth";
	char str6[10]="fifth";
	int i;

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;


	i=add_to_list(head,str1);
	i=add_to_list(head,str2);
	i=add_to_list(head,str3);
	i=add_to_list(head,str4);
	i=add_to_list(head,str5);
	i=add_to_list(head,str6);

	EXPECT_EQ(linkedlist_status(head),7);

}

TEST(status,onlyhead)
{
	char str[15]="List Start";

	linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

	head->next=NULL;
	head->data=str;
	head->index=0;

	EXPECT_EQ(linkedlist_status(head),1);

}
