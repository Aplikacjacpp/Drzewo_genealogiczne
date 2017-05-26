/***************************************************************************************************************
*"definition.h"
*
*
*
*
*
*CONTENTS:
* "Definicje header'ów klas"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     09.05.2017  Orginal design													  			Lukasz Janus
****************************************************************************************************************/

#ifndef DEFINITON_H
#define DEFINITON_H

//definition from type - dane
#define n_first_name "$0"
#define n_last_name  "&0"
#define n_gender   "!0"
#define n_parent   "r0"
#define n_day   "D0"
#define n_month   "D1"
#define n_year   "D2"
#define n_id_personaly "d0"
#define n_id_data   "d0"
#define n_id_relation   "d0"
#define n_children   "r1"
#define n_sibling   "r2"
#define n_grandparent   "r3"
#define n_grandchildren   "r4"
#define n_partner "r5"
#define n_order   "r6"
#define n_gender_personaly   "~0"
#define n_gender_date   "~1"
#define n_gender_relation "~2"
//definition from type - typ
#define t_first_name   84
#define t_last_name   86 //
#define t_gender   81
#define t_parent   162
#define t_day   116
#define t_month   117
#define t_year   118
#define t_id_personaly   148
#define t_id_data   149
#define t_id_relation   157	//
#define t_children   163
#define t_sibling   164
#define t_grandparent   165
#define t_grandchildren   166
#define t_partner 167
#define t_order   168
#define t_gender_personaly   174
#define t_gender_date   175
#define t_gender_relation   183 // 
//definition from file
#define f_save_data "data.save"
#define f_save_relation "relation.save"
#define f_save_date "date.save"
#define f_init_file "file"
#define f_end_file "#@#@#@#@#@#@#@#@#@"
#endif // !DEFINITON_H
