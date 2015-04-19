#ifndef ID3_H_INCLUDED
#define ID3_H_INCLUDED


/*
    Data structure datasets info
*/
struct dsinfo_t
{
    char            	*name;
    long            	value;
	long				column;
    struct dsinfo_t   	*next;
    struct dsinfo_t   	*prev;
};

/*
	Data structure leaf
*/
typedef struct node_tag
{
	long				winvalue;
	long				tot_attrib;
	long				*avail_attrib;
	long				tot_samples;
	long				*samples;
	long				tot_nodes;
	struct node_tag	*nodes;
} node_t;



#endif // ID3_H_INCLUDED
