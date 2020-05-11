typedef struct linkStack {
	char data;
	struct linkStack *next;
} linkStack_t;

int linkStackPush(linkStack_t **top, char data) {
	linkStack_t *newNode = malloc(sizeof(linkStack_t));
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;

	return 0;
}

int linkStackPop(linkStack_t **top, char *data) {
	if (NULL == top || NULL == *top)
		return -1;

	linkStack_t *popNode = *top;
	*top = (*top)->next;
	*data = popNode->data;
	free(popNode);

	return 0;
}

int linkStackEmpty(linkStack_t *top) {
	return (top == NULL) ? 1 : 0;
}

enum {
	NEED_PUSH = 0,
	NEED_POP = 1,
};

int charValueCheck(char value) {
	switch (value) {
	case '(':
	case '[':
	case '{':
		return NEED_PUSH;
	case ')':
	case ']':
	case '}':
		return NEED_POP;
	default:
		return -1;
	}
}

char coupleValueGet(char value) {
	switch (value) {
	case '(':
		return ')';
	case '[':
		return ']';
	case '{':
		return '}';
	case ')':
		return '(';
	case ']':
		return '[';
	case '}':
		return '{';
	default:
		return ' ';
	}
}

bool isValid(char *s) {
	int i = 0;
	char value, couple;
	linkStack_t *top = NULL;
	int strLen = strlen(s);

	for (i = 0; i < strLen; i++) {
		if (NEED_PUSH == charValueCheck(s[i])) {

			if (0 != linkStackPush(&top, s[i])) {
				return false;
			}
		}
		else {

			if (0 == linkStackPop(&top, &value) && value == coupleValueGet(s[i])) {
				continue;
			}
			else {
				return false;
			}
		}
	}

	if (linkStackEmpty(top)) {
		return true;
	}
	else {
		return false;
	}
}
