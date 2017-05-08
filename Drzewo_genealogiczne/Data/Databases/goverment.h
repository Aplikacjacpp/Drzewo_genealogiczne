#ifndef GOVERMENT_H
#define GOVERMENT_H
class C_goverment
{
public:
	C_goverment();
	C_goverment(const C_goverment & goverment);
	C_goverment& operator=(const C_goverment& goverment);
	bool operator==(const C_goverment& goverment);
	bool operator!=(const C_goverment& goverment);
	virtual ~C_goverment();
};
#endif // !GOVERMENT_H



