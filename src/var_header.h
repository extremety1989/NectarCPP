/*
 * This file is part of NectarCPP
 * Copyright (c) 2020 - 2020 Adrien THIERRY
 * https://nectar-lang.org - https://seraum.com/
 *
 * sources : https://github.com/nectar-lang/NectarCPP
 * 
 * NectarCPP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * NectarCPP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with NectarCPP.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 
namespace Nectar
{
	union Data
	{
		void* ptr;
		double number;
		char* str;
		
	};
	
	struct VAR
	{
		Nectar::Enum::Type type;
		std::bitset<2> property; // const, enumerable
		Data data;
		
		VAR();
		~VAR();

		/**/
		VAR(VAR const &_v);
		VAR(VAR const &&_v);
		/**/
		
		/*** CONSTRUCTOR ***/

		VAR(Nectar::Enum::Type _type, int _value);
		VAR(Nectar::Enum::Type _type, double _value);
		VAR(int _value);
		VAR(double _value);
		VAR(long long _value);
		VAR(char *_value);
		VAR(std::string _value);
		VAR(const char *_value);
		VAR(Nectar::Class::FixedArray *_value);
		VAR(Nectar::Class::Array *_value);
		VAR(const Nectar::Class::Array *_value);
		VAR(bool _value);
		VAR(Nectar::Class::Function *_value);
		VAR(Nectar::Class::Object *_value);
		VAR(Nectar::Class::String *_value);
		VAR(Nectar::Class::Native *_value);
		VAR(Nectar::Class::Undefined *_value);
		VAR(void *_value, void* fn);
		VAR(Nectar::Enum::Type _type, void *_value);
		VAR(Nectar::Enum::Type _type, void *_value, VAR _this);
		VAR(std::function<VAR(Nectar::VAR*, int)> &_value);
		template <class... Args>
		VAR operator() (Args... args);
		template <class... Args>
		VAR operator() (Args... args) const;
		
		/* END CALL OVERLOAD */

		VAR & operator[] (VAR _index);
		VAR & operator[] (VAR _index) const;
		VAR & operator[] (int _index) const;
		VAR & operator[] (int _index);
		VAR & operator[] (double _index);
		VAR & operator[] (const char* _index);
		/* END ACCESS OVERLOAD */

		/*** END CONSTRUCTOR ***/

		/*** OPERATOR ***/
		void operator=(const VAR &_v);

		/// Unary operators
		VAR operator+();
		VAR operator-();
		VAR operator!();

		/// Logical operators
		VAR operator&&(const VAR &_v1);
		VAR operator||(const VAR &_v1);

		/// Arithmetic operators
		VAR operator+(const VAR &_v1);
		VAR operator+(const char _v1[]);
		VAR& operator+=(const VAR &_v1);
		VAR operator-(const VAR &_v1);
		VAR& operator-=(const VAR &_v1);
		VAR operator*(const VAR &_v1);
		VAR& operator*=(const VAR &_v1);
		VAR operator/(const VAR &_v1);
		VAR& operator/=(const VAR &_v1);
		VAR operator%(const VAR &_v1);
		VAR& operator%=(const VAR &_v1);
		// TODO: "**" and "**=" operators
		VAR& operator++(const int _v1);
		VAR& operator++();
		VAR& operator--(const int _v1);
		VAR& operator--();
		/// Comparison operators
		VAR operator==(const VAR &_v1);
		// === emulated with __Nectar_EQUAL_VALUE_AND_TYPE
		VAR operator!=(const VAR &_v1);
		// !== emulated with __Nectar_NOT_EQUAL_VALUE_AND_TYPE
		VAR operator<(const VAR &_v1);
		VAR operator<=(const VAR &_v1);
		VAR operator>(const VAR &_v1);
		VAR operator>=(const VAR &_v1);
		/// Bitwise operators
		VAR operator&(const VAR &_v1);
		VAR& operator&=(const VAR &_v1);
		VAR operator|(const VAR &_v1);
		VAR operator|=(const VAR &_v1);
		VAR operator^(const VAR &_v1);
		VAR operator^=(const VAR &_v1);
		VAR operator~();
		VAR operator>>(const VAR &_v1);
		VAR operator>>=(const VAR &_v1);
		VAR operator<<(const VAR &_v1);
		VAR operator<<=(const VAR &_v1);

		explicit operator int() const;
		operator int();
		explicit operator double() const;
		operator double();
		explicit operator bool() const;
		operator bool();
		explicit operator std::string() const;
		operator std::string();
		explicit operator const char*() const;
		explicit operator long long();
		explicit operator long long() const;
		
	};
} // namespace Nectar