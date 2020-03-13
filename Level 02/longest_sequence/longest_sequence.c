/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:53:01 by vilee             #+#    #+#             */
/*   Updated: 2020/03/12 17:39:33 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};
#define MAX_THREE(a,b,c) ((a > b) ? ((a > c) ? a : c) : (b > c) ? b : c);

typedef struct s_node	t_node;

int		recursion(t_node *node, int *longest)
{
	if (node == 0)
		return (0);
	int	left = recursion(node->left, longest);
	int right = recursion(node->right, longest);
	int	continuity = 0;
	if (node->left && (node->left->value == node->value + 1))
	{
		left++;
		continuity++;
	}
	if (node->right && (node->right->value == node->value + 1))
	{
		right++;
		continuity++;
	}
	int local_max = MAX_THREE(1, left, right);
	if (local_max > *longest)
		*longest = local_max;
	return (continuity ? local_max : 1);
}

int		longest_sequence(struct s_node *node)
{
	int		ret = 0;
	recursion(node, &ret);
	return (ret);
}

// #include <stdio.h>
// #define NODE(v,l,r) &(t_node){v,l,r}

// int		main(void)
// {
// 	// 	Example 1:

// 	//        10
// 	//        /
// 	//       5
// 	//      / \
// 	//     /   \
// 	//    6    9
// 	//   / \
// 	//  /   \
// 	// 7   13
// 	//	Answer should be 3 (5->6->7)

// 	t_node *example1 = 
// 		NODE(10, 
// 			NODE(5, 
// 				NODE(6, NODE(7,0,0), NODE(13,0,0)),
// 				NODE(9,0,0)),
// 			0);
// 	printf("Example 1 = %d\n", longest_sequence(example1));
// 	// 	Example 2:

// 	//    5
// 	//   / \
// 	//  /   \
// 	// 6     4
// 	//     /  \
// 	//    9    3
// 	//  /  \    \
// 	// 3    2    2
// 	// Answer should be 2 (5->6)

// 	t_node *example2 =
// 		NODE(5,
// 			NODE(6,0,0),
// 			NODE(4,
// 				NODE(9,
// 					NODE(3,0,0),
// 					NODE(2,0,0)), 
// 				NODE(3,0,
// 					NODE(2,0,0))));
// 	printf("Example 2 = %d\n", longest_sequence(example2));
// 	// Example 3: 

// 	//     30
// 	//     / \
// 	//    /   \
// 	//   15   41
// 	//  /     /
// 	// 61    80
// 	t_node *example3 = 
// 		NODE(30, 
// 			NODE(15,NODE(61,0,0),0), 
// 			NODE(41,NODE(80,0,0),0));
// 	printf("Example 3 = %d\n", longest_sequence(example3));
	
// 	t_node *example4 = NULL;
// 	printf("Example 14= %d\n", longest_sequence(example4));
// }