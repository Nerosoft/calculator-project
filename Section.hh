class Section {
public:
	Section() = default;
	enum class MenuEdit {
		add,
		search,
		update_item,
		message102,
		message101,
		message103,
		first_opration,
		message104,
		chose_operation,
		exit

	};
	enum class InputValid {
		addition,
		input_mark_search,
		input_mark_update_add,
		input_user,
		input_mark
	};

	enum class InputKey {
		addition,
		search,
		edit,
		deletion,
		first_call_add,
		first_call_search,
		first_call_edit
	};
};