#include <stdlib.h>
#include <stdio.h>

typedef struct		s_file
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int	main(void)
{
	t_list	*buff;

	buff = (t_list*)malloc(sizeof(t_list));
	printf("Lol, Im contents of newly created t_list or whatever\n");
	printf("buff->content is '%s'\nbuff.content_size is '%ul'buff->next is '%ul'\n", buff->content, buff->content_size, buff->next);

	return (0);
}