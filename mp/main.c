#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

//#include "id3.h"

//#define DO_DEBUG

#ifdef DO_DEBUG
#define	DEBUG	printf
#else
#define	DEBUG(...) do{}while(0);
#endif

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

char *dataset[] =
{
// 	attr 1		attr 2		attr 3		attr 4		classes
"Wednesday ",	"Afternoon",	"cool",	"dark    ",	"YES",
"Tuesday   ",	"Morning  ",	"cold",	"bright  ",	"YES",
"Thursday  ",	"Night    ",	"cool",	"bright  ",	"YES",
"Thursday  ",	"Afternoon",	"cool",	"dim     ",	"NO",
"Wednesday ",	"Night    ",	"cool",	"dim     ",	"NO",
"Wednesday ",	"Night    ",	"hot ",	"moderate",	"YES",
"Monday    ",	"Afternoon",	"cool",	"bright  ",	"NO",
"Wednesday ",	"Morning  ",	"cool",	"bright  ",	"YES",
"Monday    ",	"Afternoon",	"cool",	"dark    ",	"NO",
"Saturday  ",	"Morning  ",	"hot ",	"moderate",	"YES",
"Monday    ",	"Night    ",	"hot ",	"moderate",	"YES",
"Wednesday ",	"Night    ",	"hot ",	"dim     ",	"NO",
"Saturday  ",	"Afternoon",	"cold",	"moderate",	"NO",
"Sunday    ",	"Morning  ",	"hot ",	"dark    ",	"YES",
"Saturday  ",	"Night    ",	"cool",	"dim     ",	"YES",
"Tuesday   ",	"Afternoon",	"cool",	"dark    ",	"YES",
"Friday    ",	"Afternoon",	"hot ",	"dark    ",	"YES",
"Thursday  ",	"Morning  ",	"hot ",	"bright  ",	"NO",
"Friday    ",	"Night    ",	"hot ",	"bright  ",	"YES",
"Sunday    ",	"Night    ",	"hot ",	"dim     ",	"YES",
"Friday    ",	"Night    ",	"cool",	"dim     ",	"NO",
"Monday    ",	"Afternoon",	"hot ",	"dim     ",	"NO",
"Wednesday ",	"Night    ",	"cool",	"dark    ",	"NO",
"Friday    ",	"Night    ",	"cool",	"moderate",	"NO",
"Thursday  ",	"Morning  ",	"hot ",	"bright  ",	"YES",
"Tuesday   ",	"Night    ",	"cold",	"bright  ",	"NO",
"Thursday  ",	"Morning  ",	"hot ",	"dim     ",	"NO",
"Wednesday ",	"Night    ",	"cool",	"dim     ",	"NO",
"Sunday    ",	"Afternoon",	"cold",	"dark    ",	"NO",
"Monday    ",	"Morning  ",	"cool",	"dim     ",	"NO",
"Saturday  ",	"Morning  ",	"cold",	"dim     ",	"YES",
"Monday    ",	"Afternoon",	"hot ",	"dim     ",	"YES",
"Tuesday   ",	"Morning  ",	"cool",	"dark    ",	"YES",
"Monday    ",	"Afternoon",	"cool",	"bright  ",	"NO",
"Monday    ",	"Afternoon",	"cool",	"dark    ",	"YES",
"Tuesday   ",	"Night    ",	"hot ",	"dim     ",	"NO",
"Monday    ",	"Morning  ",	"hot ",	"dim     ",	"YES",
"Sunday    ",	"Morning  ",	"hot ",	"dim     ",	"YES",
"Friday    ",	"Afternoon",	"cool",	"bright  ",	"YES",
"Friday    ",	"Afternoon",	"cold",	"moderate",	"YES",
"Monday    ",	"Afternoon",	"cold",	"dim     ",	"YES",
"Monday    ",	"Night    ",	"cool",	"dim     ",	"YES",
"Saturday  ",	"Morning  ",	"hot ",	"bright  ",	"YES",
"Tuesday   ",	"Afternoon",	"hot ",	"bright  ",	"NO",
"Friday    ",	"Night    ",	"cold",	"moderate",	"NO",
"Wednesday ",	"Afternoon",	"hot ",	"bright  ",	"NO",
"Saturday  ",	"Night    ",	"cool",	"bright  ",	"YES",
"Monday    ",	"Night    ",	"cold",	"moderate",	"NO",
"Wednesday ",	"Night    ",	"hot ",	"dim     ",	"NO",
"Wednesday ",	"Night    ",	"cool",	"dim     ",	"YES",
"Wednesday ",	"Morning  ",	"hot ",	"moderate",	"YES",
"Wednesday ",	"Afternoon",	"cool",	"dim     ",	"NO",
"Sunday    ",	"Afternoon",	"hot ",	"bright  ",	"YES",
"Monday    ",	"Morning  ",	"hot ",	"moderate",	"NO",
"Tuesday   ",	"Morning  ",	"cool",	"dim     ",	"NO",
"Wednesday ",	"Afternoon",	"cool",	"dark    ",	"YES",
"Sunday    ",	"Night    ",	"cold",	"bright  ",	"NO",
"Tuesday   ",	"Afternoon",	"hot ",	"dark    ",	"NO",
"Thursday  ",	"Morning  ",	"cold",	"bright  ",	"YES",
"Tuesday   ",	"Morning  ",	"hot ",	"dim     ",	"YES",
"Tuesday   ",	"Night    ",	"cold",	"bright  ",	"NO",
"Wednesday ",	"Night    ",	"hot ",	"dim     ",	"NO",
"Saturday  ",	"Night    ",	"hot ",	"dim     ",	"YES",
"Tuesday   ",	"Night    ",	"hot ",	"bright  ",	"NO",
"Monday    ",	"Morning  ",	"hot ",	"bright  ",	"YES",
"Friday    ",	"Afternoon",	"cold",	"dark    ",	"YES",
"Tuesday   ",	"Morning  ",	"hot ",	"dark    ",	"YES",
"Saturday  ",	"Morning  ",	"hot ",	"bright  ",	"NO",
"Tuesday   ",	"Morning  ",	"hot ",	"moderate",	"YES",
"Sunday    ",	"Night    ",	"cold",	"bright  ",	"NO",
"Wednesday ",	"Afternoon",	"cold",	"dim     ",	"NO",
"Saturday  ",	"Afternoon",	"hot ",	"bright  ",	"NO",
"Friday    ",	"Night    ",	"cold",	"dark    ",	"YES",
"Monday    ",	"Morning  ",	"hot ",	"dim     ",	"YES",
"Monday    ",	"Night    ",	"hot ",	"dark    ",	"YES",
"Friday    ",	"Night    ",	"cold",	"moderate",	"NO",
"Wednesday ",	"Night    ",	"hot ",	"dim     ",	"NO",
"Saturday  ",	"Afternoon",	"cold",	"moderate",	"YES",
"Saturday  ",	"Morning  ",	"cold",	"moderate",	"YES",
"Monday    ",	"Afternoon",	"cold",	"moderate",	"NO",
"Wednesday ",	"Afternoon",	"cold",	"dark    ",	"YES",
"Thursday  ",	"Night    ",	"cold",	"dim     ",	"NO",
"Monday    ",	"Afternoon",	"cold",	"bright  ",	"NO",
"Wednesday ",	"Night    ",	"cool",	"dim     ",	"YES",
"Wednesday ",	"Night    ",	"hot ",	"dark    ",	"NO",
"Monday    ",	"Afternoon",	"cool",	"dim     ",	"YES",
"Wednesday ",	"Morning  ",	"cool",	"bright  ",	"NO",
"Wednesday ",	"Afternoon",	"cool",	"bright  ",	"NO",
"Monday    ",	"Night    ",	"cool",	"bright  ",	"YES",
"Sunday    ",	"Afternoon",	"hot ",	"moderate",	"NO",
"Thursday  ",	"Night    ",	"cool",	"dim     ",	"YES",
"Monday    ",	"Afternoon",	"cold",	"moderate",	"YES",
"Saturday  ",	"Night    ",	"cool",	"dim     ",	"NO",
"Sunday    ",	"Morning  ",	"cool",	"moderate",	"NO",
"Wednesday ",	"Night    ",	"cool",	"dim     ",	"NO",
"Thursday  ",	"Morning  ",	"cool",	"moderate",	"NO",
"Saturday  ",	"Morning  ",	"cold",	"dark    ",	"NO",
"Wednesday ",	"Morning  ",	"cold",	"dim     ",	"YES",
"Saturday  ",	"Morning  ",	"cold",	"dark    ",	"NO",
"Monday    ",	"Morning  ",	"cool",	"bright  ",	"YES",
};

/*
	Before scanning decision tree to collect
	info about the depth of the branches and the maximum number
	maximum of rules created
*/
void scantree( node_t *node, long *max_depth, long *max_rules  )
{
	static int depth = 0;
	int j, i;

	if( node != NULL )
	{
		depth += 1;

		// Store the depth max branches
		if( depth > *max_depth ) *max_depth = depth;

		// stores the maximum number of rules found
		if( node->tot_nodes == 0 ) *max_rules += 1;

		j = 0;
		while( j < node->tot_nodes )
		{
			scantree( node->nodes+j, max_depth, max_rules );

			depth -= 1;
			++j;
		}
	}
}

/*
	Second scan decision tree for the collection of
rules for each class
*/
void scanrules( node_t *node, long class_id, long *depth, long *path, long maxdepth, long *table, long *tid )
{
	int j, i;

	if( node != NULL )
	{
		*depth += 1;

		// update the current path
		*( path + ( *depth - 1 ) ) = node->winvalue;

		// and ' the utlimo leaf node of the branch
		if( node->tot_nodes == 0 && node->winvalue == class_id )
		{
			for( i = 0; i < *(depth)-1; i++ )
				*( table + ((*tid)*maxdepth) + i ) = path[ i ];
				*(tid)	+=1;
		}

		j = 0;
		while( j < node->tot_nodes )
		{
			scanrules( node->nodes+j, class_id, depth, path, maxdepth, table, tid );

			*depth -= 1;
			++j;
		}
	}
}
/*
	Extraction of the rules contained in the tree of decisions
*/
void explain_rules( node_t *node, long cols, struct dsinfo_t *info, char **titles, long maxdepth, long maxrules )
{
	struct dsinfo_t 	*infoptr 		= info;
	struct dsinfo_t 	*infoptr2 		= NULL;
	long				*rules_table	= NULL;
	long				tableins_id		= 0;
	long				rulestable_sz	= 0;
	long				*temp_path		= NULL;
	long				attrb			= 0;
	long				attrb_id		= 0;
	long				*attrb_name		= 0;
	long				depth			= 0;
	long				i, j, k;

	// allocating memory to hold the rules
	rulestable_sz 	= sizeof( long ) * maxdepth * maxrules;
	rules_table 	= malloc( rulestable_sz );
	temp_path 		= malloc( sizeof( long ) * maxdepth );

	printf( "Rules found:\n\n");
	while( infoptr->next != NULL )
	{
		if( infoptr->column == ( cols - 1 ) )
		{
			printf( "class %s\n", infoptr->name );

			i = 0;
			while( i < ( maxdepth * maxrules ) )
			{
				*( rules_table + i ) = -1;
				++i;
			}

			for( i = 0; i < maxdepth; i++ )	temp_path[ i ] = -1;
			depth 		= 0;
			tableins_id = 0;
			scanrules( node, infoptr->value, &depth, temp_path, maxdepth, rules_table, &tableins_id );


			/*
				Classe (4): NO
								-1  0  2 -1
								-1  8  5 -1
								-1 -1 -1 -1
								-1 -1 -1 -1
								-1 -1 -1 -1
				Classe (7): YES
								-1  0 11 -1
								-1  6 -1 -1
								-1  8  3 -1
								-1 -1 -1 -1
								-1 -1 -1 -1
			*/
			// Print the rules found for the current class
			printf("\t\t");
			for( i = 0; i < maxrules; i++ )
			{
				for( j = 0; j < (maxdepth-1); j++ )
				{
					attrb 		= *( rules_table + i*maxdepth + j );
					if( attrb >= 0 )
					{
						attrb_id 	= 0;
						infoptr2 	= info;
						while( infoptr2 != NULL )
						{
							if( attrb == infoptr2->value )
							{
								attrb_id 	= infoptr2->column;
								attrb_name 	= infoptr2->name;
								break;
							}
							infoptr2 = infoptr2->next;
						}
						printf( "se %s = %s ", *( titles + attrb_id ), attrb_name );
						if( *( rules_table + i*maxdepth + j+1 ) >= 0 )
							printf( "e " );
						else
							printf( "\n\t\t" );
					}
				}
			}
			printf("\n");

		}
		infoptr = infoptr->next;
	}

	free( temp_path );
	free( rules_table );
}

/*
Entropy calculation portion of samples
- Data : pointer to the entire DataBase
- Cols : number of columns DB ( + attributes classes )
- Sample : vector containing the indices of the samples to be analyzed
- Totsamples : total samples to be analyzed
- Information : information about classes / atttributi
*/
double calc_entropy_set( long *data, long cols, long *samples, long totsamples, struct dsinfo_t *info )
{
	double 			entropy		= 0;
	double				part		= 0;
	long				total		= 0;
	struct dsinfo_t  	*infoptr	= NULL;
	long				j;

	// try within the infolist indices of classes
	infoptr = info;
	while( infoptr != NULL )
	{
		// when I find a class ...
		if( infoptr->column == ( cols - 1 ) )
		{
			// we calculate the entropy on the portion of the database indicated by samples
			// Samples contains the indices of the sample to be analyzed percutaneous
			// Data [ samples [ j ] * cols + cols - 1 ] contains the value of the class (last column )
			// Element of the DB index indicated by samples [ j ]

			total = 0;
			for( j = 0; j < totsamples; j++ )
				if( data[ samples[ j ]*cols + cols - 1 ] == infoptr->value ) ++total;

			// calculating the ratio on which to perform the formula
			if( total > 0 && totsamples > 0 )
			{
				part	= (double)total / (double)totsamples;

				// high entropy total entropy for this class
				// The formula Entropy = -p ( I) log2 ( p ( I) )
				entropy += ( -part * log2(part) );
			}
		}
		// continuous research in info
		infoptr = infoptr->next;
	}

	return entropy;
}


/*Calculation Info gain for an attribute
*/
double calc_attrib_gain( long *data, long cols, long *samples, long totsamples, struct dsinfo_t *info, long attrib )
{
	struct dsinfo_t  	*infoptr 		= NULL;
	long				tot_attribtype 	= 0;
	long				tot_classtype	= 0;
	double 			gain 			= 0;
	double				vpcgain			= 0;
	double				part			= 0;
	long				size			= 0;
	long				attrvalue		= 0;
	long				*classlist		= NULL;
	long				i = 0, j, k;

	struct vpc_t
	{
		long			class_id;
		long			tot_found;
	};

	struct gdata_t
	{
		long			value;
		long			tot_found;
		struct vpc_t	*vpc;
	};
	struct gdata_t		*gdata, *gdataptr;
	struct	vpc_t		*vpcptr;

	// Calculating total possible values ​​for attribute and classes
	infoptr = info;
	while( infoptr != NULL )
	{
		// total count possible values ​​for the attribute
		if( infoptr->column == attrib ) 		++tot_attribtype;
		// total count possible values ​​for classes
		if( infoptr->column == ( cols - 1 ) ) 	++tot_classtype;
		// I continue the search
		infoptr = infoptr->next;
	}

	// classlist becomes a vector containing all possible classes
	classlist = malloc( sizeof( long ) * tot_classtype );
	infoptr = info , i = 0;
	while( infoptr != NULL )
	{
		if( infoptr->column == ( cols - 1 ) ) *( classlist + i++ ) = infoptr->value;
		infoptr = infoptr->next;
	}

	// Memory allocation for facilities for each type of attribute value
	size 	= sizeof( struct gdata_t ) * tot_attribtype;
	gdata 	= malloc( size );
	memset( gdata, 0, size );

	// Initialization structure for each attribute value
	i = 0, infoptr = info;
	while( infoptr != NULL )
	{
		if( infoptr->column == attrib )
		{
			gdataptr 				= gdata + i;
			gdataptr->value 		= infoptr->value;
			gdataptr->tot_found 	= 0;

			size = sizeof( struct vpc_t ) * tot_classtype;
			gdataptr->vpc 			= malloc( size );

			for( j = 0; j < tot_classtype; j++ )
			{
				vpcptr 				= gdataptr->vpc + j;
				vpcptr->class_id	= *( classlist + j );
				vpcptr->tot_found	= 0;
			}
			++i;
		}
// I continue research
		infoptr = infoptr->next;
	}

	// Collection of data from the samples with respect to the number of values for each
	// Attribute; for each value is also calculated how many match
	// To a class rather than another
	for( i = 0; i < totsamples; i++ )
	{
		for( j = 0; j < tot_attribtype; j++ )
		{

			gdataptr = gdata + j;
			if( gdataptr->value == data[ samples[ i ]*cols + attrib ] )
			{
				gdataptr->tot_found += 1;
				for( k = 0; k < tot_classtype; k++ )
				{
					vpcptr = gdataptr->vpc;
					if( data[ samples[ i ]*cols + cols - 1 ] == ( vpcptr+k )->class_id )
							( vpcptr+k )->tot_found += 1;
				}
			}
		}
	}

	// Computing information gain
	for( i = 0; i < tot_attribtype; i++ )
	{
		gdataptr 	= gdata + i;
		vpcgain		= 0;

		for( j = 0; j < tot_classtype; j++ )
		{
			vpcptr 	= 	gdataptr->vpc + j;
			if( vpcptr->tot_found > 0 && gdataptr->tot_found > 0 )
			{
				part	= 	(double)vpcptr->tot_found / (double)gdataptr->tot_found;
				vpcgain +=	( -( part ) * log2( part ) );
			}
 		}
		if( gdataptr->tot_found > 0 && totsamples > 0 )
		{
			part	= (double) gdataptr->tot_found / (double) totsamples;
			gain 	+= ( -( part ) * vpcgain );
		}
	}

	// Free all memory allocated
	for( i = 0; i < tot_attribtype; i++ )
	{
		gdataptr = gdata + i;
		free( gdataptr->vpc );
	}
	free( gdata );
	free( classlist );

	return 	gain;
}

/*
	Creating nodes tree
*/
void create_leaves( node_t *node, long *data, long cols, long rows, struct dsinfo_t *info )
{

	struct dsinfo_t  	*infoptr 		= NULL;
	double 			entropy_set 	= 0;
	double				*gains			= NULL;
	double				max_gain		= 0;
	long				max_gain_id		= 0;
	long				gbuf_sz			= 0;
	long				max_attr_values	= 0;
	long				tot_new_samples	= 0;
	long				tot_avattrib	= 0;
	long				*sampleptr		= NULL;
	node_t				*node_ptr		= NULL;
	node_t				*new_node		= NULL;
	long				j, i;

	struct smplid_t
	{
		long 				value;
		struct smplid_t 	*next;
		struct smplid_t 	*prev;
	};

	struct smplid_t	*samplelist		= NULL;
	struct smplid_t	*samplelistptr	= NULL;
	struct smplid_t	*samplelistprv	= NULL;


	DEBUG( "Current node @ %p:\n", node );
	DEBUG( "\twinvalue        : %d\n", node->winvalue );
	DEBUG( "\ttot_samples     : %d\n", node->tot_samples );
	DEBUG( "\tsamples         : " );
	for( i = 0; i < node->tot_samples; i++ )
		DEBUG( "%-2d ", node->samples[ i ] );
	DEBUG( "\n\ttot_attrib      : %d (%d %d %d %d )\n", node->tot_attrib, node->avail_attrib[0],node->avail_attrib[1],node->avail_attrib[2],node->avail_attrib[3] );
	DEBUG( "\ttot_nodes       : %d\n", node->tot_nodes );
	DEBUG( "\tnodes           @ %p\n", node->nodes );


	// entropy calculation of the part of samples to be examined
	entropy_set = calc_entropy_set( data, cols, node->samples, node->tot_samples, info );

	DEBUG( "Entropy set = %3.6f\n", entropy_set );
	// The value of entropy_set and 'fundamental to continue or not in the CREATION
	// Branches and leaf nodes. If its value and '0 means that the elements
	// Prerfettamente examined are classified, and if its value 'means that
	// Elements have no rules, are totally random.
	// If the value and 'between 0 and 1 continuation and calculating the gain for each
	// Values available ..
	if( entropy_set == 0.000f )
	{

		node->nodes 				= malloc( sizeof( node_t ) );
		node->tot_nodes				= 1;
		node->nodes->tot_nodes 		= 0;
		node->nodes->winvalue 		= data[ node->samples[ 0 ] * cols + cols - 1 ];

		node->nodes->tot_attrib		= 0;
		node->nodes->avail_attrib	= NULL;
		node->nodes->tot_samples	= 0;
		node->nodes->samples		= NULL;
		node->nodes->nodes			= NULL;

		DEBUG( "\t\t\tNodo Terminale @ %p:\n", node->nodes );
		DEBUG( "\t\t\twinvalue        : %d\n", node->nodes->winvalue );
		DEBUG( "\t\t\ttot_samples     : %d\n", node->nodes->tot_samples );
		DEBUG( "\t\t\ttot_attrib      : %d\n", node->nodes->tot_attrib );
		DEBUG( "\t\t\ttot_nodes       : %d\n", node->nodes->tot_nodes );
		DEBUG( "\t\t\tnodes           @ %p\n", node->nodes->nodes );
	}
	else if( entropy_set == 1 )
	{
		//Data totally random, no rules
	}
	else
	{
		// calculates the total of the attributes on which to calculate ...
		tot_avattrib = 0;
		for( j = 0; j < ( cols - 1 ); j++ )
			if( node->avail_attrib[ j ] == 1 ) tot_avattrib += 1;

		DEBUG( "\tEntropy calculation for each attribute (tot. Available% d)\n", tot_avattrib );
		// if there is 'more' of an attribute available
		if( tot_avattrib > 0 )
		{

			// allocating memory for the buffer of size n. attributes
			// Within the buffer
			gains = malloc( sizeof( double ) * ( cols - 1 ) );
			for( i = 0; i < ( cols - 1 ); i++ ) gains[ i ] = 0;

			for( j = 0; j < ( cols - 1 ); j++ )
				if( node->avail_attrib[ j ] == 1 )
				{
					gains[ j ] = entropy_set + calc_attrib_gain( data, cols, node->samples, node->tot_samples, info, j );
					DEBUG( "\tInfo Gain per attribute %d = %3.3f\n", j, gains[ j ] );
				}
			// Look for the value more 'high ...
			for( j = 0; j < ( cols - 1 ); j++ )
				if( gains[ j ] > max_gain )
				{
					max_gain	= gains[ j ];
					max_gain_id = j;
				}

			// calculates the maximum possible number of values for the attribute winning
			max_attr_values = 0;
			infoptr 		= info;
			while( infoptr != NULL )
			{
				if( infoptr->column == max_gain_id ) ++max_attr_values;
				infoptr = infoptr->next;
			}
			DEBUG( "\tThe attribute %d has the highest IG (%3.3f) and %d types of values \n", max_gain_id, max_gain, max_attr_values );

			//creates nodes for each possible value of the attribute
			// The number of nodes and 'equal to all possible values for the attribute
			node->nodes 	= ( node_t* ) malloc( sizeof( node_t ) * max_attr_values );
			node->tot_nodes = max_attr_values;
			DEBUG( "\tAllocating memory for %d knots @ %p\n", max_attr_values, node->nodes );

			infoptr 		= info;
			j = 0;
			while( infoptr != NULL )
			{
				if( infoptr->column == max_gain_id )
				{
					DEBUG( "\t\tSetting node %d value of the attribute%d\n", infoptr->value, max_gain_id );

					node_ptr 	= node->nodes;
					node_ptr 	+= j;
					DEBUG( "\t\t\tnode_ptr = %p ( j = %d )\n", node_ptr, j );

					tot_new_samples = 0;
					// Search the sample DB indicated by node-> all samples
					// Those in the column indicated by max_gain_id have the indicated value
					// From infoptr-> value, to calculate the total and put it in tot_samples
					// Create a vector of dimension tot_samples and assign it to node_ptr-> samples
					for( i = 0; i < node->tot_samples; i++ )
					{
						if( data[ node->samples[ i ] * cols + max_gain_id ] == infoptr->value )
						{
							if( samplelist == NULL )
							{
								samplelist 				= malloc( sizeof( struct smplid_t ) );
								samplelist->value 		= node->samples[ i ];
								samplelist->next		= NULL;
								samplelist->prev		= NULL;
							}
							else
							{
								samplelistptr				= samplelist;
								while( samplelistptr->next != NULL ) samplelistptr = samplelistptr->next;
								samplelistptr->next			= malloc( sizeof( struct smplid_t ) );
								samplelistptr->next->prev 	= samplelistptr;
								samplelistptr 				= samplelistptr->next;
								samplelistptr->value 		= node->samples[ i ];
								samplelistptr->next			= NULL;
							}
							tot_new_samples += 1;
						}
					}

					node_ptr->winvalue		= infoptr->value;
					node_ptr->tot_nodes 	= 0;
					node_ptr->tot_samples 	= tot_new_samples;
					node_ptr->samples		= malloc( sizeof( long ) * tot_new_samples );
					sampleptr				= node_ptr->samples;

					samplelistptr			= samplelist;
					while( samplelistptr != NULL )
					{
						*( sampleptr++ ) 	= samplelistptr->value;
						samplelistptr 		= samplelistptr->next;
					}
					// Once inserted the indices of the new sample in the test vector
					// Pointed to by node_ptr-> samples can destroy the temporary list
					samplelistptr			= samplelist;
					samplelistprv			= samplelist;
					while( samplelistptr != NULL )
					{
						samplelistprv = samplelistptr->next;
						free( samplelistptr );
						samplelistptr = samplelistprv;
					}
					samplelist = NULL;

					node_ptr->tot_attrib 	= ( cols - 1 );
					node_ptr->avail_attrib	= malloc( sizeof( long ) * ( cols - 1 ) );

					for( i = 0; i < cols-1; i++ )
						node_ptr->avail_attrib[ i ] = node->avail_attrib[ i ];
					node_ptr->avail_attrib[ max_gain_id ] = 0;

					DEBUG( "\t\t\tnode_ptr->winvalue    : %d\n", node_ptr->winvalue );
					DEBUG( "\t\t\tnode_ptr->tot_samples : %d\n", node_ptr->tot_samples );
					DEBUG( "\t\t\tnode_ptr->samples     : %p\n", node_ptr->samples );


					// Recursive creation of the leaf nodes
					if( node_ptr->tot_samples > 0 ) create_leaves( node_ptr, data, cols, rows, info );


					++j;
				}
				infoptr = infoptr->next;
			}
			free( gains );
		}
		else
		{
			node->nodes 				= malloc( sizeof( node_t ) );
			node->tot_nodes				= 1;
			node->nodes->tot_nodes 		= 0;
			node->nodes->winvalue 		= data[ node->samples[ 0 ] * cols + cols - 1 ];

			node->nodes->tot_attrib		= 0;
			node->nodes->avail_attrib	= NULL;
			node->nodes->tot_samples	= 0;
			node->nodes->samples		= NULL;
			node->nodes->nodes			= NULL;

			DEBUG( "\t\t\tNodo terminal @ %p:\n", node->nodes );
			DEBUG( "\t\t\twinvalue        : %d\n", node->nodes->winvalue );
			DEBUG( "\t\t\ttot_samples     : %d\n", node->nodes->tot_samples );
			DEBUG( "\t\t\ttot_attrib      : %d\n", node->nodes->tot_attrib );
			DEBUG( "\t\t\ttot_nodes       : %d\n", node->nodes->tot_nodes );
			DEBUG( "\t\t\tnodes           @ %p\n", node->nodes->nodes );
		}
	}
}



/*
creating rules
*/
int id3tree_create( char **data, long cols, long rows, ... )
{
    long				*dataset		= NULL;
	unsigned long		dataset_sz 		= 0;
	struct dsinfo_t  	*infolist		= NULL;
	struct dsinfo_t  	*insptr 		= NULL;
	struct dsinfo_t  	*prvptr 		= NULL;
	struct dsinfo_t  	*prvass 		= NULL;
	char				label_found		= 0;
	char				infolisterror	= 0;
	long				string_id		= 0;
	long				assign_id		= 0;
	node_t		*root			= NULL;

	va_list				llistptr;
	char				**cols_titles	= NULL;
	char				**ctptr			= NULL;
	char				*label;
	long				totlabels		= 0;

	long				tree_max_depth	= 0;
	long				tree_max_rules	= 0;


	int					result			= 0;
	int 				i = 0, j = 0, col = 0;

	DEBUG( "ID3 Init: cols = %d rows = %d dataset %p\n", cols, rows, data );

	do {

		// Filling the list of pointers to string containing
		// Labels (titles) for each attribute
		va_start( llistptr, rows );
		do {
			label = va_arg( llistptr, int );
			if( label != NULL ) totlabels += 1;
		} while( label != NULL );
		va_end( llistptr );

		cols_titles = malloc( sizeof( char* )*totlabels );
		// Check if I can allocate memory for labels
		if( cols_titles == NULL )
		{
			result = -1;
			break;
		}
		// Fill the vector with dimension equal to the number of columns of the newly created database
		ctptr = cols_titles;
		va_start( llistptr, rows );
		for( i = 0; i < totlabels; i++ )
		{
			label 	= va_arg( llistptr, int );
			*ctptr 	= label;
			++ctptr;
		}
		va_end( llistptr );

		DEBUG( "Columns labels:\n" );
		for( i = 0; i < totlabels; i++ )
			DEBUG( "Label %3d = %s\n", i, cols_titles[ i ] );


			// Since the comparison of long values more 'faster than the
			// Comparison of strings the entire data set is made up of strings
			// Converted by assigning a unique index to each string
			// Calculate amount 'of memory required for the conversion table
		dataset_sz = sizeof( long ) * cols * rows;

		// Allocate memory for conversion stringa-> value
		if( ( dataset = malloc( dataset_sz ) ) == NULL )
		{
			result = -2;
			break;
		}
		// I reset the table completely
		memset( dataset, 0, dataset_sz );


		// The entire data set (string) is completely for last
// Retrieve all the necessary information to the calculations for the creation
// Tree rules
		i = 0, col = 0;
		while( i < (cols*rows) )
		{
			// If infolist and 'NULL means that the element is obviously included in the list
			insptr = NULL;
			if( infolist == NULL )
			{
				infolist 	= malloc( sizeof( struct dsinfo_t ) );
				if( infolist == NULL )
				{
					infolisterror = 1;
					break;
				}
				// TODO insert control value infolist
				insptr		= infolist;
				prvass		= NULL;
			}
			else
			{
				// Otherwise it is sought among all those found so far. if not stated
				// The list is added
				insptr 		= infolist;
				prvptr		= infolist;
				label_found	= 0;
				do {
					if( !strcmp( insptr->name, data[ i ] ) )
					{
						label_found = 1;
						assign_id	= insptr->value;
						insptr		= NULL;
						break;
					}
					prvptr	= insptr;
					insptr 	= insptr->next;
				} while( insptr != NULL );

				if( label_found == 0 )
				{
					prvptr->next 	= malloc( sizeof( struct dsinfo_t ) );
					if( prvptr->next == NULL )
					{
						infolisterror = 1;
						break;
					}
					insptr			= prvptr->next;
					prvass			= prvptr;
				}
			}
			// If insptr and 'NULL means pointing to an area of memory
			// Already 'allocated to contain the data on the new label
			if( insptr != NULL )
			{
				assign_id		= string_id;
				insptr->name 	= malloc( sizeof( char )*strlen( data[ i ] ) + 1 );
				if( insptr->name == NULL )
				{
					infolisterror = 1;
					break;
				}

				sprintf( insptr->name, data[ i ] );
				insptr->value	= string_id++;
				insptr->column	= col;
				insptr->next	= NULL;
				insptr->prev	= prvass;
			}

			// Update the corresponding long in the conversion table String-> long
			dataset[ i ] = assign_id;


			// With the variable takes into account the current column in the dataset
			// If queuing keeps track of the attribute / class to which the item belongs
			if( ++col >= cols ) col = 0;
			// Increment index sliding elements in the dataset
			i += 1;
		}
		// Check if there were memory allocation errors when creating the dataset
		if( infolisterror )
		{
			result = -3;
			break;
		}


		// Create the root node: from here the creation of the whole tree
		if( ( root = ( node_t* ) malloc( sizeof( node_t ) ) ) == NULL )
		{
			result = -4;
			break;
		}
		// Being at the root of the set of samples to be tested and 'the whole tree
		root->tot_samples	= rows;
		// Create a vector containing the indices (0 to row - 1) of all the samples to be examined
		if( ( root->samples = malloc( sizeof( long ) * rows ) ) == NULL )
		{
			result = -5;
			break;
		}
		// The root node contains the indices of all the samples in the database
		for( j = 0; j < rows; j++ ) root->samples[ j ] = j;

		// Imposed all the possible attributes (all columns minus one, the one of the classes)
		root->tot_attrib = ( cols - 1 );
		// All the attributes (cols - 1) must be taken into account
		if( ( root->avail_attrib	= malloc( sizeof( long ) * ( cols - 1 ) ) ) == NULL )
		{
			result = -6;
			break;
		}
		// The root node all the attributes are to be checked
		for( j = 0; j < ( cols - 1 ); j++ ) root->avail_attrib[ j ] = 1;

		// Value (-1) that identifies the root node, the node also has (at the beginning) in knots
		root->winvalue		= -1;
		root->tot_nodes		= 0;

		DEBUG( "Root node @ %p:\n", root );
		DEBUG( "\twinvalue        : %d\n", root->winvalue );
		DEBUG( "\ttot_samples     : %d\n", root->tot_samples );
		DEBUG( "\tsamples         : " );
		for( i = 0; i < root->tot_samples; i++ )
			DEBUG( "%2d ", root->samples[ i ] );
		DEBUG( "\n\ttot_attrib      : %d (%d %d %d %d )\n", root->tot_attrib, root->avail_attrib[0],root->avail_attrib[1],root->avail_attrib[2],root->avail_attrib[3] );
		DEBUG( "\ttot_nodes       : %d\n", root->tot_nodes );
		DEBUG( "\tnodes           @ %p\n", root->nodes );


		// Creating tree and leaf nodes
		create_leaves( root, dataset, cols, rows, infolist );

		// Display tree
		scantree( root, &tree_max_depth, &tree_max_rules );

		// Explanation of the rules
		explain_rules( root, cols, infolist, cols_titles, tree_max_depth, tree_max_rules );

	} while( 0 );

	// TODO Free Memory

	// Free memory dataset info
	insptr = infolist;
	while( insptr != NULL )
	{
		prvass = insptr->next;
		free( insptr );
		insptr = prvass;
	}
	// Free memory allocated for the table conversion stringa-> value
	if( dataset != NULL ) 	free( dataset );
	// Free memory allocated label attributes / classes
	if( cols_titles != NULL ) free( cols_titles );

	return result;
}



int main()
{
    int result = 0;


    // Function to create the decision tree is id3tree_create()

    result = id3tree_create( 	dataset,			// pointer to the database
								5,					// Total columns ( attributes + classes) in the dataset
								100,					// total samples in the database (rows)
								"day",			// label for attribute 1
								"time",		// label for attribute 2
								"temp",			// label for attribute 3
								"light",				// label for attribute 4
								"on",			// label for classes
								NULL				// NULL terminator
							);
    printf( "outcome : %d\n", result );


    return 0;
}