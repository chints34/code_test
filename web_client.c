//#include <stdio.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>
//#include <stdlib.h>
//#include <netdb.h>
//#include <string.h>
//
//
//int create_tcp_socket();
//char *get_ip(char *host);
//char *build_get_query(char *host, char *page);
//void usage();
//
//#define HOST "coding.debuntu.org"
//#define PAGE "/"
//#define PORT 8510
//#define USERAGENT "HTMLGET 1.0"
//
//int main(int argc, char **argv) {
//	struct sockaddr_in *remote;
//	int sock;
//	int tmpres;
//	char *ip;
//	char *get;
//	char buf[BUFSIZ + 1];
//	char *host;
//	char *page;
//
//	if (argc == 1) {
//		usage();
//		exit(2);
//	}
//	host = argv[1];
//	if (argc > 2) {
//		page = argv[2];
//	} else {
//		page = PAGE;
//	}
//	sock = create_tcp_socket();
//	char *h = "192.168.101.138";
//	ip = h;
//	fprintf(stderr, "IP is %s\n", ip);
//	remote = (struct sockaddr_in *) malloc(sizeof(struct sockaddr_in *));
//	remote->sin_family = AF_INET;
//	tmpres = inet_pton(AF_INET, ip, (void *) (&(remote->sin_addr.s_addr)));
//	if (tmpres < 0) {
//		perror("Can't set remote->sin_addr.s_addr");
//		exit(1);
//	} else if (tmpres == 0) {
//		fprintf(stderr, "%s is not a valid IP address\n", ip);
//		exit(1);
//	}
//	remote->sin_port = htons(PORT);
//
//	if (connect(sock, (struct sockaddr *) remote, sizeof(struct sockaddr))
//			< 0) {
//		perror("Could not connect");
//		exit(1);
//	}
//	get = build_get_query(host, page);
//	fprintf(stderr, "Query is:\n<<START>>\n%s<<END>>\n", get);
//
//	//Send the query to the server
//	int sent = 0;
//	while (sent < strlen(get)) {
//		tmpres = send(sock, get + sent, strlen(get) - sent, 0);
//		if (tmpres == -1) {
//			perror("Can't send query");
//			exit(1);
//		}
//		sent += tmpres;
//	}
//	//now it is time to receive the page
//	memset(buf, 0, sizeof(buf));
//	int htmlstart = 0;
//	char * htmlcontent;
//	while ((tmpres = recv(sock, buf, BUFSIZ, 0)) > 0) {
//		if (htmlstart == 0) {
//			/* Under certain conditions this will not work.
//			 * If the \r\n\r\n part is splitted into two messages
//			 * it will fail to detect the beginning of HTML content
//			 */
//			htmlcontent = strstr(buf, "\r\n\r\n");
//			if (htmlcontent != NULL) {
//				htmlstart = 1;
//				htmlcontent += 4;
//			}
//		} else {
//			htmlcontent = buf;
//		}
//		if (htmlstart) {
//			fprintf(stdout, htmlcontent);
//		}
//
//		memset(buf, 0, tmpres);
//	}
//	if (tmpres < 0) {
//		perror("Error receiving data");
//	}
//	free(get);
//	free(remote);
//	free(ip);
//	close(sock);
//	return 0;
//}
//
//void usage() {
//	fprintf(stderr,
//			"USAGE: htmlget host [page]\n\
//    \thost: the website hostname. ex: coding.debuntu.org\n\
//    \tpage: the page to retrieve. ex: index.html, default: /\n");
//}
//
//int create_tcp_socket() {
//	int sock;
//	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
//		perror("Can't create TCP socket");
//		exit(1);
//	}
//	return sock;
//}
//
//char *get_ip(char *host) {
//	struct hostent *hent;
//	int iplen = 15; //XXX.XXX.XXX.XXX
//	char *ip = (char *) malloc(iplen + 1);
//	memset(ip, 0, iplen + 1);
//	if ((hent = gethostbyname(host)) == NULL) {
//		herror("Can't get IP");
//		exit(1);
//	}
//	if (inet_ntop(AF_INET, (void *) hent->h_addr_list[0], ip, iplen) == NULL) {
//		perror("Can't resolve host");
//		exit(1);
//	}
//	return ip;
//}
//
//char *build_get_query(char *host, char *page) {
//	char *query;
//	char *getpage = page;
//	char *tpl = "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
//	if (getpage[0] == '/') {
//		getpage = getpage + 1;
//		fprintf(stderr, "Removing leading \"/\", converting %s to %s\n", page,
//				getpage);
//	}
//	// -5 is to consider the %s %s %s in tpl and the ending \0
//	query = (char *) malloc(
//			strlen(host) + strlen(getpage) + strlen(USERAGENT) + strlen(tpl)
//					- 5);
//	sprintf(query, tpl, getpage, host, USERAGENT);
//	return query;
//}




// to prepare a binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct binary
{
	int data;
	struct binary *left;
	struct binary *right;
}tree;
void add(tree**,int);
void print(tree *);
tree * search(tree *,tree *,int);
void del(tree **,int);
tree *par=NULL,*temp=NULL;
main()
{
	tree *root=NULL;
	char ch;
	int n,n1;
	while(1)
	{
		printf("/////////////////////// binary search tree///////////////////\n");
		printf("a:add a node to binary tree\n");
		printf("p:print the tree\n");
		printf("s:search the node in tree\n");
		printf("d:delete a node in tree\n");
		printf("e:exit \n");
		printf("enter the choice\n");
		scanf(" %c",&ch);

		switch(ch)
		{
			case 'a':printf("enter the data\n");
				 scanf("%d",&n);
				add(&root,n);
				break;
			case 'p':print(root);
				break;
			case 's':printf("enter node to search\n");
				scanf("%d",&n1);
				search(root,root,n1);
				break;
			case 'd':printf("enter node to be deleted\n");
				 scanf("%d",&n1);
				del(&root,n1);
				break;
			case 'e':exit(0);
				break;
			default:printf("invalid entry\n");

		}

	}

}
////////////////////////add func////////

void add(tree **ptr,int n)
{
	if((*ptr)==NULL)
	{
		(*ptr)=malloc(sizeof(tree));
		(*ptr)->data=n;
		(*ptr)->left=NULL;
		(*ptr)->right=NULL;

	}
	else
	{
		if(n <(*ptr)->data)
		{
			add(&((*ptr)->left),n);
		}
		else
		{
			add(&((*ptr)->right),n);
		}

	}
	return;
}

//////////////////////////print function//////////////

void print(tree *ptr)
{
	if(ptr)
	{
		printf("%d->",ptr->data);//preorder
		print(ptr->left);
		//printf("%d",ptr->data);//inorder
		print(ptr->right);
//		printf("%d->",(ptr)->data);//postorder

	}
	return;
}

////////////////////////search func////////////////////

tree *search(tree *ptr,tree *pr,int n)
{

	temp=ptr;
	if(ptr==NULL)
	printf("node not found\n");

	else if((ptr->data)==n)
	{
		printf("node found\n");
		return(pr);
	}

	else
	{

	 	if((ptr->data)>n)
		{
			pr=ptr;
			pr=search(ptr->left,pr,n);
			return (pr);
		}

		else
		{
			pr=ptr;
			pr=search(ptr->right,pr,n);
			return (pr);
		}
	}
}

////////////////////delete func/////////////

void del(tree **ptr1,int n)
{
	tree *pr;
	par=search((*ptr1),(*ptr1),n);
	printf("par=%d\t",par->data);
//	printf("temp->data %d\n",temp->data);
// delete a leaf
	if((temp->left==0)&&(temp->right==0))
	{
		if(par->left==temp)
		{
			par->left=0;
		}
		else
		{
			par->right=0;
		}
		free(temp);
	}
// to delete a child
	if(((temp->left==0)&&(temp->right))||((temp->left)&&(temp->right==0)))
	{
		if(par->left==temp)
		{
			if(temp->right)
			par->left=temp->right;
			else
			par->left=temp->left;

		}
		else
		{
			if(temp->left)
			par->right=temp->left;
			else
			par->right=temp->right;
		}
		free(temp);
	}
// to delete a parent
	if((temp->left)&&(temp->right))
	{
		par=temp;
		temp=temp->right;
	//	par=temp;
		while(temp->left)
		{	pr=temp;	//pr for left side last data delet use
			temp=temp->left;
		}
		par->data=temp->data;// delet node if both chilld available
			//than parent right side to last left side data copy
		printf("dpar->data %d\t",par->data);
		//printf("npar->data %d\t",par->right->data);
		if((temp->left==0)&&(temp->right==0))
		{
			if(pr->left==temp)
			{
				pr->left=0;
			}
			else
			{
				pr->right=0;
			}
			free(temp);
		}
		if(((temp->left==0)&&(temp->right))||((temp->left)&&(temp->right==0)))
		{
			if(pr->left==temp)
			{
				if(temp->right)
				pr->left=temp->right;
				else
				pr->left=temp->left;
			}
			else
			{
				if(temp->left)
				pr->right=temp->left;
				else
				pr->right=temp->right;
			}
			free(temp);
		}
	}
	return;
}

