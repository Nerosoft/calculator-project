class Section {
public:
	Section() = default;
	enum class MenuEdit {
		add,
		search,
		update_item,
		first_opration,
		chose_operation,
		message104,
		message102,
		message101,
		message103,
		addition,
		input_mark_search,
		input_mark_update_add
	};


	enum class InputKey {
		addition,
		search,
		edit,
		deletion,
		first_call_add,
		first_call_search,
		first_call_edit,
		confirm
	};
};