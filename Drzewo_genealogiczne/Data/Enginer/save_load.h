#ifndef C_SAVE_LOAD_H
#define C_SAVE_LOAD_H
class C_save_load
{
public:
	C_save_load();
	C_save_load(const C_save_load & save_load);
	C_save_load& operator=(const C_save_load& save_load);
	bool operator==(const C_save_load& save_load);
	bool operator!=(const C_save_load& save_load);
	virtual ~C_save_load();
};
#endif // !C_SAVE_LOAD_H



