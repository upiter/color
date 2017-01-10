/*
   Copyright 2016 Dejan D. M. Milosavljevic

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
namespace color {
namespace akin {

template< typename category_name >
struct cmy {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct cmyk {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct gray {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct hsl {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct hsv {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct rgb {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct yiq {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace constant {
namespace yuv {

enum reference_enum {
	error_entity
	,BT_601_entity
	,BT_709_entity
};

}
}
}

namespace color {
namespace akin {

template< typename category_name, ::color::constant::yuv::reference_enum reference_number >
struct yuv {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct xyz {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace type {

template< typename index_name >
struct index {
public:
	typedef index_name instance_type;

	typedef instance_type const const_type;

	typedef instance_type const& return_image_type;
	typedef instance_type return_type;
	typedef instance_type & return_original_type;

	typedef instance_type const& input_const_type, param_const_input_type;
	typedef instance_type input_type, param_input_type;
	typedef instance_type & output_type, param_output_type;
	typedef instance_type & transmit_type, param_transmit_type;
};

}
}
}
}

namespace color {
namespace trait {

template< typename category_name >
struct index
	: public ::color::_internal::utility::type::index< unsigned > {
public:

	typedef ::color::_internal::utility::type::index< unsigned > utility_type;

	typedef typename utility_type::instance_type instance_type;

	typedef typename utility_type::const_type const_type;

	typedef typename utility_type::return_image_type return_image_type;
	typedef typename utility_type::return_original_type return_original_type;

	typedef typename utility_type::input_const_type input_const_type;
	typedef typename utility_type::input_type input_type;
	typedef typename utility_type::output_type output_type;
};

}
}

namespace color {
namespace trait {

template< typename category_name , unsigned index_size = 0 >
struct component {
public:
	typedef unsigned char instance_type;
	typedef instance_type const const_type;

	typedef instance_type const return_image_type;
	typedef instance_type return_type;
	typedef instance_type return_original_type;

	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;

};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace type {

template < typename number_name, typename image_name = number_name const& >
struct bound {
public:
	typedef number_name number_type;
	typedef image_name image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value=0;
		return value;
	}

	static image_type minimum() {
		static number_type value=0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<bool, bool const& > {
	typedef bool number_type;
	typedef bool const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = true;
		return value;
	}

	static image_type minimum() {
		static number_type value = false;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<std::uint8_t, std::uint8_t const& > {
	typedef std::uint8_t number_type;
	typedef std::uint8_t const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 255;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<std::uint16_t, std::uint16_t const& > {
	typedef std::uint16_t number_type;
	typedef std::uint16_t const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 0xFFFF;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<std::uint32_t, std::uint32_t const& > {
	typedef std::uint32_t number_type;
	typedef std::uint32_t const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 0xFFFFFFFF;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<std::uint64_t, std::uint64_t const& > {
	typedef std::uint64_t number_type;
	typedef std::uint64_t const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 0xFFFFFFFFFFFFFFFFu;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<float, float const& > {
	typedef float number_type;
	typedef float const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value=1;
		return value;
	}

	static image_type minimum() {
		static number_type value=0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<double, double const& > {
	typedef double number_type;
	typedef double const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value=1;
		return value;
	}

	static image_type minimum() {
		static number_type value=0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<long double, long double const& > {
	typedef long double number_type;
	typedef long double const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 1;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}

};

}
}
}
}

namespace color {
namespace _internal {
namespace utility {
namespace type {

template < typename type_name >
struct traitC {
public:
	typedef type_name instance_type;

	typedef instance_type const const_type ;

	typedef instance_type const& return_image_type;
	typedef instance_type return_type ;

	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type input_value_type;

};

}
}
}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename value_name, typename index_name >
struct general {
public:
	typedef value_name value_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< value_name > component_trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename component_trait_type::instance_type component_instance_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	typedef ::color::_internal::utility::type::bound< component_instance_type, component_return_const_type > bound_type;

	template< index_instance_type index >
	static component_return_const_type maximum() {
		static const component_instance_type component = bound_type::maximum();
		return component;
	}

	static component_return_const_type maximum(index_input_const_type index) {
		static const component_instance_type component = bound_type::maximum();
		return component;
	}

	template< index_instance_type index >
	static component_return_const_type minimum() {
		static const component_instance_type component = bound_type::minimum();
		return component;
	}

	static component_return_const_type minimum(index_input_const_type index) {
		static const component_instance_type component = bound_type::minimum();
		return component;
	}

	template< index_instance_type index >
	static component_return_const_type range() {
		static const component_instance_type component = bound_type::range();
		return component;
	}

	static component_return_const_type range(index_input_const_type index) {
		static const component_instance_type component = bound_type::range();
		return component;
	}
};

}
}
}
}

namespace color {

namespace trait {
template< typename category_name >
struct bound
	: public ::color::_internal::utility::bound::general
	  <
	  typename ::color::trait::component< category_name >::instance_type
	,typename ::color::trait::index< category_name >::instance_type
	  > {
public:
	typedef category_name category_type;

	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::index< category_name > index_trait_type;

	typedef typename component_trait_type::instance_type component_instance_type;
	typedef typename index_trait_type::instance_type index_instance_type;

	typedef ::color::_internal::utility::bound::general<component_instance_type, index_instance_type > general_type;

	using general_type::minimum;
	using general_type::maximum;
	using general_type::range;
};

}
}

namespace color {
namespace trait {

template< typename category_name >
struct scalar
	: public ::color::_internal::utility::type::traitC< double > {
public:
	typedef double instance_type;

	static bool is_small(instance_type const& value) {
		return (-1e-6 < value) && (value < 1e-6);
	}
};

}
}

namespace color {
namespace _internal {

template< typename category_name >
struct diverse {
public:
	typedef typename ::color::trait::scalar<category_name>::instance_type scalar_type;
	typedef ::color::trait::bound< category_name > bound_trait_type;
	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::index< category_name > index_trait_type;

	typedef typename component_trait_type::instance_type component_instance_type;
	typedef typename component_trait_type::return_type component_return_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	static
	component_return_type
	process(scalar_type const& normal, index_input_const_type index) {
		scalar_type divergent = normal;
		divergent *= bound_trait_type::range(index);
		divergent += bound_trait_type::minimum(index);
		return component_instance_type(divergent);
	}

	template< index_instance_type index_size >
	static
	component_return_type
	process(scalar_type const& normal) {
		scalar_type divergent = normal;
		divergent *= bound_trait_type::template range<index_size>();
		divergent += bound_trait_type::template minimum<index_size>();
		return component_instance_type(divergent);
	}
};

}
}
namespace color {
namespace _internal {

template< typename category_name >
struct normalize {
public:
	typedef typename ::color::trait::scalar<category_name>::instance_type scalar_type;
	typedef ::color::trait::bound< category_name > bound_trait_type;
	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::index< category_name > index_trait_type;

	typedef typename component_trait_type::instance_type component_instance_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	static
	scalar_type
	process(component_input_const_type divergent, index_input_const_type index) {
		scalar_type normal = static_cast<component_instance_type>(divergent);
		normal -= bound_trait_type::minimum(index);
		normal /= bound_trait_type::range(index);
		return normal;
	}

	template< index_instance_type index_size >
	static
	scalar_type
	process(component_input_const_type divergent) {
		scalar_type normal = static_cast<component_instance_type>(divergent);
		normal -= bound_trait_type::template minimum<index_size>();
		normal /= bound_trait_type::template range<index_size>();
		return normal;
	}

};

}
}

namespace color {
namespace _internal {

template
<
	typename category_left_name
	,typename category_right_name
	,typename scalar_name
	>
struct reformat {
public:
	typedef category_left_name category_left_type;
	typedef category_right_name category_right_type;
	typedef scalar_name scalar_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef typename ::color::trait::component< category_left_name >::return_type left_component_return_type;
	typedef typename ::color::trait::index< category_left_name >::input_const_type left_index_const_input_type;
	typedef typename ::color::trait::index< category_left_name >::instance_type left_index_instance_type;

	typedef typename ::color::trait::component< category_right_name >::input_const_type right_component_const_input_type;
	typedef typename ::color::trait::index< category_right_name >::input_const_type right_index_const_input_type;
	typedef typename ::color::trait::index< category_right_name >::instance_type right_index_instance_type;

	static
	left_component_return_type
	process
	(
		left_index_const_input_type left_index
		,right_component_const_input_type right_component
		,right_index_const_input_type right_index
	) {
		return diverse_type::process
			   (
				   normalize_type::process
				   (
					   right_component
					   ,right_index
				   )
				   , left_index
			   );
	}

	template
	<
		left_index_instance_type left_index_size
		>
	static
	left_component_return_type
	process
	(
		right_component_const_input_type right_component
		,right_index_const_input_type right_index
	) {
		return diverse_type::template process< left_index_size >
		(
			normalize_type::process
			(
				right_component
				,right_index
			)
		);
	}

	template
	<
		left_index_instance_type left_index_size
		,right_index_instance_type right_index_size
		>
	static
	left_component_return_type
	process
	(
		right_component_const_input_type right_component
	) {
		return diverse_type::template process< left_index_size >
		(
			normalize_type::template process< right_index_size >
			(
				right_component
			)
											);
	}
};

template
<
	typename category_name
	>
struct reformat< category_name, category_name, typename ::color::trait::scalar<category_name>::instance_type > {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar<category_name>::instance_type scalar_type;

	typedef typename ::color::trait::component< category_type >::return_type component_return_type;
	typedef typename ::color::trait::index< category_type >::input_const_type index_const_input_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	typedef typename ::color::trait::component< category_type >::input_const_type component_const_input_type;

	static
	component_return_type
	process
	(
		index_const_input_type left_index
		,component_const_input_type right_component
		,index_const_input_type right_index
	) {
		return right_component;
	}

	template
	<
		index_instance_type left_index_size
		>
	static
	component_return_type
	process
	(
		component_const_input_type right_component
		,index_const_input_type right_index
	) {
		return right_component;
	}

	template
	<
		index_instance_type left_index_size
		,index_instance_type right_index_size
		>
	static
	component_return_type
	process
	(
		component_const_input_type right_component
	) {
		return right_component;
	}
};

}
}

namespace color {
namespace trait {

template< typename category_name >
struct container {
public:
	typedef unsigned int instance_type;

	typedef instance_type const const_type;

	typedef instance_type const return_image_type;
	typedef instance_type & return_type;
	typedef instance_type & return_original_type;

	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type, param_output_type;

	typedef ::color::trait::index< category_name > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::const_type index_const_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::trait::component< category_name > component_trait_type;
	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;
	typedef typename component_trait_type::instance_type component_type;

	typedef void set_return_type;

	enum { size_entity = 4 };

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		return (component_type)((container >> (index << 3)) & 0xFF);
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		return (component_type)((container >> (index << 3)) & 0xFF);
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		container = (container & ~(0xFF << (index << 3))) | (((instance_type)value) << (index << 3));
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		container = (container & ~(0xFF << (index << 3))) | (((instance_type)value) << (index << 3));
	}

	static index_return_image_type size() {
		static index_instance_type length = 4;
		return length;
	}
};

}
}

namespace color {
namespace _internal {

template< typename category_left_name, typename category_right_name >
struct convert {
public:
	typedef category_left_name category_left_type;
	typedef category_right_name category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::index<category_left_type> index_trait_type;
	typedef typename index_trait_type::instance_type index_type;

	typedef ::color::trait::container< category_left_type > container_left_trait_type;
	typedef ::color::trait::container< category_right_type > container_right_trait_type;

	typedef ::color::trait::component<category_left_type> component_trait_type;
	typedef typename component_trait_type::instance_type component_left_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	static
	void
	process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static const index_type min_common_size = std::min< index_type >(container_left_trait_type::size(), container_right_trait_type::size());
		component_left_type value;
		for(index_type index=0; index < min_common_size; ++index) {
			value = reformat_type::process(index, container_right_trait_type::get(right, index), index);
			container_left_trait_type::set(left, index, value);
		}
	}
};

template< typename category_name >
struct convert< category_name,category_name > {
public:

	typedef ::color::trait::container< category_name > container_trait_type;

	typedef typename container_trait_type::input_type container_input_type;
	typedef typename container_trait_type::input_const_type container_const_input_type;

	static
	void
	process
	(
		container_input_type left
		,container_const_input_type right
	) {
		left = right;
	}

};

}
}
namespace color {
namespace _internal {

template< typename category_name >
void init
(
	typename ::color::trait::container< category_name >::output_type container
	, std::initializer_list< typename ::color::trait::component< category_name >::instance_type > const& ilist
) {
	typedef ::color::trait::container< category_name > container_trait_type;
	typedef typename ::color::trait::index< category_name >::instance_type index_type;
	auto ili = ilist.begin();
	index_type index=0;
	for(; index < std::min<index_type>(container_trait_type::size(), ilist.size()) ; ++index, ++ili) {
		container_trait_type::set(container, index, *ili);
	}
};

}
}

namespace color {
namespace constant {

template < typename tag_name >
struct base {
};

}
}

namespace color {
namespace constant {

template< typename constant_name, typename category_name >
struct make {
	typedef category_name category_type;
	typedef constant_name constant_type;

	typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	static void process(container_output_type & m) {
	}
};

}
}

namespace color {

template< typename category_name >
class model {
public:
	typedef category_name category_type;

	typedef ::color::trait::index< category_name > index_trait_type;
	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::container< category_name > container_trait_type;
	typedef ::color::trait::bound< category_name > bound_trait_type, bound_type;
	typedef ::color::trait::scalar< category_name > scalar_trait_type;

	typedef ::color::model<category_type> this_type, model_type;

	typedef typename index_trait_type::instance_type index_type;
	typedef typename index_trait_type::const_type index_const_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::return_type component_return_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;
	typedef typename component_trait_type::input_type component_input_type;

	typedef typename container_trait_type::instance_type container_type;
	typedef typename container_trait_type::const_type container_const_type;
	typedef typename container_trait_type::return_image_type container_return_const_type;
	typedef typename container_trait_type::return_original_type container_return_original_type;
	typedef typename container_trait_type::input_const_type container_input_const_type;
	typedef typename container_trait_type::input_type container_input_type;

	typedef typename container_trait_type::set_return_type set_return_type;

	typedef typename scalar_trait_type::input_const_type scalar_input_const_type;

	model() {
	}

	explicit model(container_input_const_type container)
		:m_container(container) {
	}

	template< typename tag_name >
	model(::color::constant::base< tag_name > const& constant) {
		*this = constant;
	}

	explicit model(std::initializer_list<component_type> const& ilist) {
		::color::_internal::init<category_name>(this->m_container, ilist);
	}

	model(::color::model<category_type> const& that) {
		this->m_container = that.container();
	}

	template< typename other_category_name >
	explicit model(::color::model<other_category_name> const& that) {
		*this = that;
	}

	template< typename tag_name >
	model & operator=(::color::constant::base< tag_name > const& constant) {
		::color::constant::make<::color::constant::base< tag_name >,category_name>::process(this->m_container);
		return *this;
	}

	template< typename other_category_name >
	model & operator=(::color::model<other_category_name> const& that) {
		::color::_internal::convert< category_name, other_category_name>::process(this->m_container, that.container());
		return *this;
	}

	component_return_const_type
	get(index_input_const_type index)const {
		return container_trait_type::get(this->m_container, index);
	}

	template< index_type index >
	component_return_const_type
	get()const {
		return container_trait_type::template get<index>(this->m_container);
	}

	set_return_type
	set(index_input_const_type index, component_input_const_type component) {
		return container_trait_type::set(this->m_container, index, component);
	}

	template< index_type index >
	set_return_type
	set(component_input_const_type component) {
		container_trait_type::template set<index>(this->m_container, component);
	}

	component_return_const_type operator[](index_input_const_type index)const {
		return this->get(index);
	}

private:
	class proxy {
	public:
		proxy(model_type & model, index_type const& index)
			: m_model(model), m_index(index) {
		}

		proxy & operator=(proxy const& that) {
			m_model.set(m_index, that.m_model.get(that.m_index));
			return *this;
		}

		proxy & operator=(component_input_const_type component) {
			m_model.set(m_index, component);
			return *this;
		}

		proxy & operator+=(component_input_const_type component) {
			m_model.set(m_index, m_model.get(m_index) + component);
			return *this;
		}

		proxy & operator-=(component_input_const_type component) {
			m_model.set(m_index, m_model.get(m_index) - component);
			return *this;
		}

		proxy & operator*=(scalar_input_const_type scalar) {
			m_model.set(m_index, m_model.get(m_index) * scalar);
			return *this;
		}

		proxy & operator/=(scalar_input_const_type scalar) {
			m_model.set(m_index, m_model.get(m_index) / scalar);
			return *this;
		}

		operator component_type()const {
			return m_model.get(m_index);
		}

	private:
		model_type & m_model;
		index_type const& m_index;
	};

	typedef typename ::color::model< category_name >::proxy proxy_type;

public:
	proxy_type operator[](index_input_const_type index) {
		return proxy{ *this, index };
	}

	container_return_const_type container()const {
		return this->m_container;
	}

	container_return_original_type container() {
		return this->m_container;
	}

	void container(container_input_const_type container) {
		this->m_container = container;
	}

	static unsigned size() {
		return container_trait_type::size();
	}

private:
	container_type m_container;
};

}

namespace color {
namespace check {
namespace _internal {

template< typename category_name >
struct integrity {
public:
	typedef category_name category_type;

	typedef ::color::model<category_type> model_type;

	static bool process(model_type const& m) {
		return true;
	}

};
}

template< typename category_name >
inline
bool integrity(::color::model<category_name> const& m) {
	return ::color::check::_internal::integrity<category_name>::process(m);
}

}
}

namespace color {
namespace check {
namespace _internal {

template< typename category_name >
struct overburn {
public:
	typedef category_name category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound<category_type> bound_type;
	typedef ::color::trait::container< category_name > container_trait_type;
	typedef ::color::trait::index<category_type> index_trait_type;

	typedef typename index_trait_type::instance_type index_type;

	static bool process(model_type const& m) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			if(m.get(index) < bound_type::minimum(index)) {
				return true;
				continue;
			}
			if(bound_type::maximum(index) < m.get(index)) {
				return true;
				continue;
			}
		}
		return container_trait_type::size();
	}

};
}

template< typename category_name >
inline
bool
overburn(::color::model<category_name> const& m) {
	return ::color::check::_internal::overburn<category_name>::process(m);
}

}
}

namespace color {
namespace constant {

namespace _internal {
struct aqua_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::aqua_type > aqua_t, aqua_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct aquamarine_type {};
}

using aquamarine_type = ::color::constant::base< ::color::constant::_internal::aquamarine_type >;
using aquamarine_t = ::color::constant::aquamarine_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct azure_type {};
}

using azure_type = ::color::constant::base< ::color::constant::_internal::azure_type >;
using azure_t = ::color::constant::azure_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct beige_type {};
}

using beige_type = ::color::constant::base< ::color::constant::_internal::beige_type >;
using beige_t = ::color::constant::beige_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct bisque_type {};
}

using bisque_type = ::color::constant::base< ::color::constant::_internal::bisque_type >;
using bisque_t = ::color::constant::bisque_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct black_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::black_type > black_t, black_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct blue_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::blue_type > blue_t, blue_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct brown_type {};
}

using brown_type = ::color::constant::base< ::color::constant::_internal::brown_type >;
using brown_t = ::color::constant::brown_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct chocolate_type {};
}

using chocolate_type = ::color::constant::base< ::color::constant::_internal::chocolate_type >;
using chocolate_t = ::color::constant::chocolate_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct coral_type {};
}

using coral_type = ::color::constant::base< ::color::constant::_internal::coral_type >;
using coral_t = ::color::constant::coral_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct crimson_type {};
}

using crimson_type = ::color::constant::base< ::color::constant::_internal::crimson_type >;
using crimson_t = ::color::constant::crimson_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct cyan_type {};
}

using cyan_type = ::color::constant::base< ::color::constant::_internal::cyan_type >;
using cyan_t = ::color::constant::cyan_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct fuchsia_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::fuchsia_type > fuchsia_t, fuchsia_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct gainsboro_type {};
}

using gainsboro_type = ::color::constant::base< ::color::constant::_internal::gainsboro_type >;
using gainsboro_t = ::color::constant::gainsboro_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct gold_type {};
}

using gold_type = ::color::constant::base< ::color::constant::_internal::gold_type >;
using gold_t = ::color::constant::gold_type;

}
}

namespace color {
namespace constant {

namespace _internal {

template< std::uintmax_t black_number, std::uintmax_t white_number = 1 >
struct gray {};

}

template< std::uintmax_t black_number, std::uintmax_t white_number >
using gray_t= ::color::constant::base< ::color::constant::_internal::gray< black_number, white_number > > ;

typedef ::color::constant::gray_t< 99, 1 > gray01_t;
typedef ::color::constant::gray_t< 95, 5 > gray05_t;
typedef ::color::constant::gray_t< 90, 10 > gray10_t;
typedef ::color::constant::gray_t< 80, 20 > gray20_t;
typedef ::color::constant::gray_t< 75, 25 > gray25_t;
typedef ::color::constant::gray_t< 70, 30 > gray30_t;
typedef ::color::constant::gray_t< 2, 1 > gray33_t;
typedef ::color::constant::gray_t< 60, 40 > gray40_t;
typedef ::color::constant::gray_t< 50, 50 > gray50_t;
typedef ::color::constant::gray_t< 40, 60 > gray60_t;
typedef ::color::constant::gray_t< 1, 2 > gray66_t;
typedef ::color::constant::gray_t< 30, 70 > gray70_t;
typedef ::color::constant::gray_t< 25, 75 > gray75_t;
typedef ::color::constant::gray_t< 20, 80 > gray80_t;
typedef ::color::constant::gray_t< 10, 90 > gray90_t;
typedef ::color::constant::gray_t< 5, 95 > gray95_t;
typedef ::color::constant::gray_t< 1, 99 > gray99_t;

namespace w3c {
typedef ::color::constant::gray50_t gray_t;
}

namespace x11 {
typedef ::color::constant::gray75_t gray_t;
}

}
}

namespace color {
namespace constant {

namespace _internal {
struct green_w3c_t {};
}

namespace w3c {
typedef ::color::constant::base< ::color::constant::_internal::green_w3c_t > green_t;
}

namespace _internal {
struct green_x11_t {};
}

namespace x11 {
typedef ::color::constant::base< ::color::constant::_internal::green_x11_t > green_t;
}

typedef ::color::constant::w3c::green_t green_t;
}
}

namespace color {
namespace constant {
namespace _internal {
struct indigo_type {};
}

using indigo_type = ::color::constant::base< ::color::constant::_internal::indigo_type >;
using indigo_t = ::color::constant::indigo_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct ivory_type {};
}

using ivory_type = ::color::constant::base< ::color::constant::_internal::ivory_type >;
using ivory_t = ::color::constant::ivory_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct khaki_type {};
}

using khaki_type = ::color::constant::base< ::color::constant::_internal::khaki_type >;
using khaki_t = ::color::constant::khaki_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct lavender_type {};
}

using lavender_type = ::color::constant::base< ::color::constant::_internal::lavender_type >;
using lavender_t = ::color::constant::lavender_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct lime_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::lime_type > lime_t, lime_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct linen_type {};
}

using linen_type = ::color::constant::base< ::color::constant::_internal::linen_type >;
using linen_t = ::color::constant::linen_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct magenta_type {};
}

using magenta_type = ::color::constant::base< ::color::constant::_internal::magenta_type >;
using magenta_t = ::color::constant::magenta_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct maroon_w3c_t {};
}

namespace w3c {
typedef ::color::constant::base< ::color::constant::_internal::maroon_w3c_t > maroon_t;
}

namespace _internal {
struct maroon_x11_t {};
}

namespace x11 {
typedef ::color::constant::base< ::color::constant::_internal::maroon_x11_t > maroon_t;
}

typedef ::color::constant::w3c::maroon_t maroon_t;

}
}

namespace color {
namespace constant {
namespace _internal {
struct moccasin_type {};
}

using moccasin_type = ::color::constant::base< ::color::constant::_internal::moccasin_type >;
using moccasin_t = ::color::constant::moccasin_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct navy_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::navy_type > navy_t, navy_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct olive_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::olive_type > olive_t, olive_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct orange_type {};
}

using orange_type = ::color::constant::base< ::color::constant::_internal::orange_type >;
using orange_t = ::color::constant::orange_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct orchid_type {};
}

using orchid_type = ::color::constant::base< ::color::constant::_internal::orchid_type >;
using orchid_t = ::color::constant::orchid_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct peru_type {};
}

using peru_type = ::color::constant::base< ::color::constant::_internal::peru_type >;
using peru_t = ::color::constant::peru_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct pink_type {};
}

using pink_type = ::color::constant::base< ::color::constant::_internal::pink_type >;
using pink_t = ::color::constant::pink_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct plum_type {};
}

using plum_type = ::color::constant::base< ::color::constant::_internal::plum_type >;
using plum_t = ::color::constant::plum_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct purple_w3c_t {};
}

namespace w3c {
typedef ::color::constant::base< ::color::constant::_internal::purple_w3c_t > purple_t;
}

namespace _internal {
struct purple_x11_t {};
}

namespace x11 {
typedef ::color::constant::base< ::color::constant::_internal::purple_x11_t > purple_t;
}

typedef ::color::constant::w3c::purple_t purple_t;

}
}

namespace color {
namespace constant {

namespace _internal {
struct red_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::red_type > red_t, red_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct salmon_type {};
}

using salmon_type = ::color::constant::base< ::color::constant::_internal::salmon_type >;
using salmon_t = ::color::constant::salmon_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct sienna_type {};
}

using sienna_type = ::color::constant::base< ::color::constant::_internal::sienna_type >;
using sienna_t = ::color::constant::sienna_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct silver_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::silver_type > silver_t, silver_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct snow_type {};
}

using snow_type = ::color::constant::base< ::color::constant::_internal::snow_type >;
using snow_t = ::color::constant::snow_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct tan_type {};
}

using tan_type = ::color::constant::base< ::color::constant::_internal::tan_type >;
using tan_t = ::color::constant::tan_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct teal_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::teal_type > teal_t, teal_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct thistle_type {};
}

using thistle_type = ::color::constant::base< ::color::constant::_internal::thistle_type >;
using thistle_t = ::color::constant::thistle_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct tomato_type {};
}

using tomato_type = ::color::constant::base< ::color::constant::_internal::tomato_type >;
using tomato_t = ::color::constant::tomato_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct turquoise_type {};
}

using turquoise_type = ::color::constant::base< ::color::constant::_internal::turquoise_type >;
using turquoise_t = ::color::constant::turquoise_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct violet_type {};
}

using violet_type = ::color::constant::base< ::color::constant::_internal::violet_type >;
using violet_t = ::color::constant::violet_type;

}
}

namespace color {
namespace constant {
namespace _internal {
struct wheat_type {};
}

using wheat_type = ::color::constant::base< ::color::constant::_internal::wheat_type >;
using wheat_t = ::color::constant::wheat_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct white_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::white_type > white_t, white_type;

}
}

namespace color {
namespace constant {

namespace _internal {
struct yellow_type {};
}

typedef ::color::constant::base< ::color::constant::_internal::yellow_type > yellow_t, yellow_type;

}
}

namespace color {
namespace type {

struct divert {};
typedef divert divert_t;

}
}

namespace color {
namespace type {

struct normal {};

typedef normal normal_t;

}
}

namespace color {
namespace type {

template< unsigned first_size, unsigned second_size >
struct pack2 {};

}
}

namespace color {
namespace type {

template< unsigned first_size, unsigned second_size, unsigned third_size >
struct pack3 {};

typedef ::color::type::pack3< 2, 3, 3 > split233_t;
typedef ::color::type::pack3< 3, 2, 3 > split323_t;
typedef ::color::type::pack3< 3, 3, 2 > split332_t;

typedef ::color::type::pack3< 4, 2, 2 > split422_t;
typedef ::color::type::pack3< 2, 4, 2 > split242_t;
typedef ::color::type::pack3< 2, 2, 4 > split224_t;

typedef ::color::type::pack3< 5, 5, 5 > split555_t;

typedef ::color::type::pack3< 6, 5, 5 > split655_t;
typedef ::color::type::pack3< 5, 6, 5 > split565_t;
typedef ::color::type::pack3< 5, 5, 6 > split556_t;

typedef ::color::type::pack3< 7, 7, 2 > split772_t;
typedef ::color::type::pack3< 7, 2, 7 > split727_t;
typedef ::color::type::pack3< 2, 7, 7 > split277_t;

typedef ::color::type::pack3< 8, 8, 8 > split888_t;

typedef ::color::type::pack3< 12, 10, 10 > splitCAA_t;
typedef ::color::type::pack3< 10, 12, 10 > splitACA_t;
typedef ::color::type::pack3< 10, 10, 12 > splitAAC_t;

}
}

namespace color {
namespace type {

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
struct pack4 {};

typedef ::color::type::pack4< 2, 2, 2, 2 > split2222_t;

typedef ::color::type::pack4< 4, 4, 4, 4 > split4444_t;

typedef ::color::type::pack4< 5, 5, 5, 1 > split5551_t;
typedef ::color::type::pack4< 1, 5, 5, 5 > split1555_t;

typedef ::color::type::pack4< 6, 6, 6, 6 > split6666_t;

typedef ::color::type::pack4< 8, 8, 8, 8 > split8888_t;

typedef ::color::type::pack4< 2, 10, 10, 10 > split2AAA_t;
typedef ::color::type::pack4< 10, 10, 10, 2 > splitAAA2_t;

typedef ::color::type::pack4< 16, 16, 16, 16 > splitGGGG_t;

}
}

namespace color {
namespace type {

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size, unsigned fifth_size >
struct pack5 {};

}
}

namespace color {
namespace type {

typedef std::array< std::uint8_t, 3 > uint24_t;

}
}

namespace color {
namespace type {

typedef std::array< std::uint8_t, 6 > uint48_t, uint48c_t;

typedef std::array< std::uint16_t, 3 > uint48s_t;

}
}

namespace color {
namespace type {

template< unsigned first_position, unsigned second_position >
struct scramble2 {

};

template< unsigned first_position, unsigned second_position, unsigned third_position >
struct scramble3 {

};

template< unsigned first_position, unsigned second_position, unsigned third_position , unsigned fourth_position >
struct scramble4 {
};

template< unsigned first_position, unsigned second_position, unsigned third_position, unsigned fourth_position, unsigned fifth_position >
struct scramble5 {
};

}
}

namespace color {
namespace type {

struct error {};

typedef error error_t;

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct red {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -1 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
red() {
	return ::color::place::_internal::red<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct green {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -8 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
green() {
	return ::color::place::_internal::green<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct blue {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -11 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
blue() {
	return ::color::place::_internal::blue<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct alpha {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -10 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
alpha() {
	return ::color::place::_internal::alpha<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct gray {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -9 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
gray() {
	return ::color::place::_internal::gray<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct hue {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -7 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
hue() {
	return ::color::place::_internal::hue<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct saturation {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -42 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
saturation() {
	return ::color::place::_internal::saturation<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct lightness {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -40 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
lightness() {
	return ::color::place::_internal::lightness<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct intensity {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -13 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
intensity() {
	return ::color::place::_internal::intensity<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct value {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -12 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
value() {
	return ::color::place::_internal::value<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct inphase {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -6 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
inphase() {
	return ::color::place::_internal::inphase<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct luma {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -41 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
luma() {
	return ::color::place::_internal::luma<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct luminance {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -3 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
luminance() {
	return ::color::place::_internal::luminance<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct quadrature {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -2 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
quadrature() {
	return ::color::place::_internal::quadrature<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct cyan {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -1 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
cyan() {
	return ::color::place::_internal::cyan<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct magenta {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -1 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
magenta() {
	return ::color::place::_internal::magenta<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct yellow {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -1 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
yellow() {
	return ::color::place::_internal::yellow<category_name>::position();
}

}
}
namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct key {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -5 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
key() {
	return ::color::place::_internal::key<category_name>::position();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
red(::color::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
green(::color::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
blue(::color::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
alpha(::color::model< category_name > const& color_parameter) {
	typedef ::color::model< category_name > model_type;
	typedef ::color::trait::bound< category_name > bound_type;
	return bound_type::template maximum< 0 >();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
gray(::color::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
hue(::color::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
luma(::color::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
red
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
}
}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
green
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
blue
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
alpha
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
gray
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
hue
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
inphase
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
key
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
luma
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
luminance
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
quadrature
(
	::color::model< category_name > & color_parameter,
	typename ::color::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace fix {

namespace _internal {

template< typename category_name >
struct integrity {
public:
	typedef category_name category_type;

	typedef ::color::model<category_type> model_type;

	static void process(model_type & m) {
	}

	static void process(model_type & result, model_type const& right) {
	}
};

}

template< typename category_name >
void integrity
(
	::color::model<category_name> & result
) {
	::color::fix::_internal::integrity<category_name>::process(result);
}

template< typename category_name >
void integrity
(
	::color::model<category_name> & result
	,::color::model<category_name> const& right
) {
	::color::fix::_internal::integrity<category_name>::process(result, right);
}

}
}

namespace color {
namespace fix {
namespace _internal {

template< typename category_name >
struct overburn {
public:
	typedef category_name category_type;

	typedef ::color::trait::index<category_type> index_trait_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::component<category_type> component_trait_type;
	typedef ::color::trait::container< category_type > container_trait_type;

	typedef typename ::color::model<category_type> model_type;

	typedef typename component_trait_type::instance_type component_type;

	typedef typename index_trait_type::instance_type index_type;

	static void process(model_type &result) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			if(result.get(index) < bound_type::minimum(index)) {
				result.set(index, bound_type::minimum(index));
				continue;
			}
			if(bound_type::maximum(index) < result.get(index)) {
				result.set(index, bound_type::maximum(index));
				continue;
			}
		}
	}

	static void process(model_type & result, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			if(right.get(index) < bound_type::minimum(index)) {
				result.set(index, bound_type::minimum(index));
				continue;
			}
			if(bound_type::maximum(index) < right.get(index)) {
				result.set(index, bound_type::maximum(index));
				continue;
			}
			result.set(index, right.get(index));
		}
	}

};

}

template< typename category_name >
void overburn
(
	::color::model<category_name> & result
) {
	::color::fix::_internal::overburn<category_name>::process(result);
}

template< typename category_name >
void overburn
(
	::color::model<category_name> & result
	,::color::model<category_name> const& right
) {
	::color::fix::_internal::overburn<category_name>::process(result, right);
}

}
}

namespace color {
namespace fix {
namespace _internal {

template< typename category_name >
struct unique {
public:
	typedef category_name category_type;

	typedef ::color::model<category_type> model_type;

	static void process(model_type & m) {
	}

	static void process(model_type & result, model_type const& right) {
	}
};

}

template< typename category_name >
void unique
(
	::color::model<category_name> & result
) {
	::color::fix::_internal::unique<category_name>::process(result);
}

template< typename category_name >
void unique
(
	::color::model<category_name> & result
	,::color::model<category_name> const& right
) {
	::color::fix::_internal::unique<category_name>::process(result, right);
}

}
}

namespace color {
namespace category {

namespace _internal {
struct generic_bool {};
struct generic_uint8 {};
struct generic_uint16 {};
struct generic_uint24 {};
struct generic_uint32 {};
struct generic_uint48 {};
struct generic_uint64 {};
struct generic_float {};
struct generic_double {};
struct generic_ldouble {};
}

template< typename tag_name>
struct generic {
};

using generic_bool = ::color::category::generic< ::color::category::_internal::generic_bool >;
using generic_uint8 = ::color::category::generic< ::color::category::_internal::generic_uint8 >;
using generic_uint16 = ::color::category::generic< ::color::category::_internal::generic_uint16 >;
using generic_uint24 = ::color::category::generic< ::color::category::_internal::generic_uint24 >;
using generic_uint32 = ::color::category::generic< ::color::category::_internal::generic_uint32 >;
using generic_uint48 = ::color::category::generic< ::color::category::_internal::generic_uint48 >;
using generic_uint64 = ::color::category::generic< ::color::category::_internal::generic_uint64 >;
using generic_float = ::color::category::generic< ::color::category::_internal::generic_float >;
using generic_double = ::color::category::generic< ::color::category::_internal::generic_double >;
using generic_ldouble = ::color::category::generic< ::color::category::_internal::generic_ldouble >;

}

}

namespace color {
namespace constant {

template< typename category_name >
struct generic {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	static scalar_type const zero() {
		return scalar_type(0);
	}
	static scalar_type const half() {
		return scalar_type(0.5);
	}
	static scalar_type const one() {
		return scalar_type(1);
	}
	static scalar_type const two() {
		return scalar_type(2);
	}
	static scalar_type const sqrt_3() {
		return sqrt(scalar_type(3));
	}
	static scalar_type const pi() {
		return scalar_type(3.141592653589793238462643383279502884197169399375105820974944592307816406286);
	}
	static scalar_type const pi_half() {
		return scalar_type(3.141592653589793238462643383279502884197169399375105820974944592307816406286/2);
	}
	static scalar_type const two_pi() {
		return scalar_type(2 * 3.141592653589793238462643383279502884197169399375105820974944592307816406286);
	}
};

namespace hue {

enum formula_enum {
	error_entity
	,hexagon_entity
	,polar_atan2_entity
	,polar_acos_entity
	,polar_entity = polar_atan2_entity
};

namespace _internal {

template < enum ::color::constant::hue::formula_enum hue_number > struct algorithm {};

}

}

}
}

namespace color {
namespace category {

template< typename tag_name >
struct cmy {
	typedef void category_name;
};

using cmy_uint8 = ::color::category::cmy< std::uint8_t >;
using cmy_uint16 = ::color::category::cmy< std::uint16_t >;

using cmy_uint32 = ::color::category::cmy< std::uint32_t >;

using cmy_uint64 = ::color::category::cmy< std::uint64_t >;
using cmy_float = ::color::category::cmy< float >;
using cmy_double = ::color::category::cmy< double >;
using cmy_ldouble = ::color::category::cmy< long double >;

}
}

namespace color {
namespace category {

template< typename tag_name >
struct gray {
	typedef void category_name;
};

using gray_bool = ::color::category::gray< bool >;
using gray_uint8 = ::color::category::gray< std::uint8_t >;
using gray_uint16 = ::color::category::gray< std::uint16_t >;

using gray_uint32 = ::color::category::gray< std::uint32_t >;

using gray_uint64 = ::color::category::gray< std::uint64_t >;
using gray_float = ::color::category::gray< float >;
using gray_double = ::color::category::gray< double >;
using gray_ldouble = ::color::category::gray< long double >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::gray_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::gray_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::gray_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::gray_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::gray_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::gray_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::gray_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct cmy< ::color::category::cmy< tag_name > > {
public:
	typedef ::color::category::cmy< tag_name > akin_type;
};

}
}

namespace color {
namespace category {

template< typename tag_name >
struct cmyk {
	typedef void category_name;
};

using cmyk_uint8 = ::color::category::cmyk< std::uint8_t >;
using cmyk_uint16 = ::color::category::cmyk< std::uint16_t >;

using cmyk_uint32 = ::color::category::cmyk< std::uint32_t >;

using cmyk_uint64 = ::color::category::cmyk< std::uint64_t >;
using cmyk_float = ::color::category::cmyk< float >;
using cmyk_double = ::color::category::cmyk< double >;
using cmyk_ldouble = ::color::category::cmyk< long double >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::cmyk_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::cmyk_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::cmyk_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::cmyk_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::cmyk_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::cmyk_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::cmyk_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace category {

template< typename tag_name >
struct hsl {
	typedef void category_name;
};

using hsl_bool = ::color::category::hsl< bool >;
using hsl_uint8 = ::color::category::hsl< std::uint8_t >;
using hsl_uint16 = ::color::category::hsl< std::uint16_t >;

using hsl_uint32 = ::color::category::hsl< std::uint32_t >;

using hsl_uint64 = ::color::category::hsl< std::uint64_t >;
using hsl_float = ::color::category::hsl< float >;
using hsl_double = ::color::category::hsl< double >;
using hsl_ldouble = ::color::category::hsl< long double >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::hsl_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::hsl_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::hsl_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::hsl_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::hsl_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::hsl_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::hsl_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace category {

template< typename tag_name >
struct hsv {
	typedef void category_name;
};

using hsv_uint8 = ::color::category::hsv< std::uint8_t >;
using hsv_uint16 = ::color::category::hsv< std::uint16_t >;

using hsv_uint32 = ::color::category::hsv< std::uint32_t >;

using hsv_uint64 = ::color::category::hsv< std::uint64_t >;
using hsv_float = ::color::category::hsv< float >;
using hsv_double = ::color::category::hsv< double >;
using hsv_ldouble = ::color::category::hsv< long double >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::hsv_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::hsv_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::hsv_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::hsv_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::hsv_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::hsv_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::hsv_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace category {

template< typename tag_name >
struct hsi {
	typedef void category_name;
};

using hsi_uint8 = ::color::category::hsi< std::uint8_t >;
using hsi_uint16 = ::color::category::hsi< std::uint16_t >;

using hsi_uint32 = ::color::category::hsi< std::uint32_t >;

using hsi_uint64 = ::color::category::hsi< std::uint64_t >;
using hsi_float = ::color::category::hsi< float >;
using hsi_double = ::color::category::hsi< double >;
using hsi_ldouble = ::color::category::hsi< long double >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::hsi_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::hsi_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::hsi_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::hsi_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::hsi_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::hsi_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::hsi_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {

namespace category {

}
}

namespace color {
namespace category {

typedef ::color::type::error_t error_t;

}
}

namespace color {
namespace category {

template< typename tag_name >
struct rgb {
	typedef tag_name tag_type;
};

template< typename tag_name >
struct rgba
	: public ::color::category::rgb< tag_name > {
	typedef tag_name tag_type;
};

namespace _internal {
template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
struct rgb_scramble : public ::color::type::scramble3< red_position, green_position, blue_position > {};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
struct rgba_scramble : public ::color::type::scramble4< red_position, green_position, blue_position, alpha_position > {};
}

namespace _internal {
using rgb_error = ::color::category::_internal::rgb_scramble< ::color::type::error_t, 0, 1, 2 >;

using rgb_uint8 = ::color::category::_internal::rgb_scramble< std::uint8_t , 0, 1, 2 >;
using rgb_uint16 = ::color::category::_internal::rgb_scramble< std::uint16_t , 0, 1, 2 >;
using rgb_uint32 = ::color::category::_internal::rgb_scramble< std::uint32_t , 0, 1, 2 >;
using rgb_uint64 = ::color::category::_internal::rgb_scramble< std::uint64_t , 0, 1, 2 >;
using rgb_float = ::color::category::_internal::rgb_scramble< float , 0, 1, 2 >;
using rgb_double = ::color::category::_internal::rgb_scramble< double , 0, 1, 2 >;
using rgb_ldouble = ::color::category::_internal::rgb_scramble< long double, 0, 1, 2 >;

template < unsigned red_size, unsigned green_size, unsigned blue_size >
using rgb_pack = ::color::category::_internal::rgb_scramble< ::color::type::pack3< red_size, green_size, blue_size >, 0, 1, 2 >;

}

using rgb_error = ::color::category::rgb< ::color::category::_internal::rgb_error >;
using rgb_uint8 = ::color::category::rgb< ::color::category::_internal::rgb_uint8 >;
using rgb_uint16 = ::color::category::rgb< ::color::category::_internal::rgb_uint16 >;
using rgb_uint32 = ::color::category::rgb< ::color::category::_internal::rgb_uint32 >;
using rgb_uint64 = ::color::category::rgb< ::color::category::_internal::rgb_uint64 >;
using rgb_float = ::color::category::rgb< ::color::category::_internal::rgb_float >;
using rgb_double = ::color::category::rgb< ::color::category::_internal::rgb_double >;
using rgb_ldouble = ::color::category::rgb< ::color::category::_internal::rgb_ldouble >;

template < unsigned red_size, unsigned green_size, unsigned blue_size >
using rgb_pack = ::color::category::rgb< ::color::category::_internal::rgb_pack< red_size, green_size, blue_size > >;

namespace _internal {
using rgba_error = ::color::category::_internal::rgba_scramble< ::color::type::error_t, 0, 1, 2, 3 >;

using rgba_uint8 = ::color::category::_internal::rgba_scramble< std::uint8_t , 0, 1, 2, 3 >;
using rgba_uint16 = ::color::category::_internal::rgba_scramble< std::uint16_t , 0, 1, 2, 3 >;
using rgba_uint32 = ::color::category::_internal::rgba_scramble< std::uint32_t , 0, 1, 2, 3 >;
using rgba_uint64 = ::color::category::_internal::rgba_scramble< std::uint64_t , 0, 1, 2, 3 >;
using rgba_float = ::color::category::_internal::rgba_scramble< float , 0, 1, 2, 3 >;
using rgba_double = ::color::category::_internal::rgba_scramble< double , 0, 1, 2, 3 >;
using rgba_ldouble = ::color::category::_internal::rgba_scramble< long double, 0, 1, 2, 3 >;

template < unsigned red_size, unsigned green_size, unsigned blue_size, unsigned alpha_size >
using rgba_pack = ::color::category::_internal::rgba_scramble< ::color::type::pack4< red_size, green_size, blue_size, alpha_size >, 0, 1, 2, 3 >;
}

using rgba_error = ::color::category::rgb< ::color::category::_internal::rgba_error >;
using rgba_uint8 = ::color::category::rgb< ::color::category::_internal::rgba_uint8 >;
using rgba_uint16 = ::color::category::rgb< ::color::category::_internal::rgba_uint16 >;
using rgba_uint32 = ::color::category::rgb< ::color::category::_internal::rgba_uint32 >;
using rgba_uint64 = ::color::category::rgb< ::color::category::_internal::rgba_uint64 >;
using rgba_float = ::color::category::rgb< ::color::category::_internal::rgba_float >;
using rgba_double = ::color::category::rgb< ::color::category::_internal::rgba_double >;
using rgba_ldouble = ::color::category::rgb< ::color::category::_internal::rgba_ldouble >;

template < unsigned red_size, unsigned green_size, unsigned blue_size, unsigned alpha_size >
using rgba_pack = ::color::category::rgb< ::color::category::_internal::rgba_pack< red_size, green_size, blue_size, alpha_size > >;

namespace _internal {
using argb_error = ::color::category::_internal::rgba_scramble< ::color::type::error_t, 3, 0, 1, 2 >;

using argb_uint8 = ::color::category::_internal::rgba_scramble< std::uint8_t , 3, 0, 1, 2 >;
using argb_uint16 = ::color::category::_internal::rgba_scramble< std::uint16_t , 3, 0, 1, 2 >;
using argb_uint32 = ::color::category::_internal::rgba_scramble< std::uint32_t , 3, 0, 1, 2 >;
using argb_uint64 = ::color::category::_internal::rgba_scramble< std::uint64_t , 3, 0, 1, 2 >;
using argb_float = ::color::category::_internal::rgba_scramble< float , 3, 0, 1, 2 >;
using argb_double = ::color::category::_internal::rgba_scramble< double , 3, 0, 1, 2 >;
using argb_ldouble = ::color::category::_internal::rgba_scramble< long double, 3, 0, 1, 2 >;

template < unsigned red_size, unsigned green_size, unsigned blue_size, unsigned alpha_size >
using argb_pack = ::color::category::_internal::rgba_scramble< ::color::type::pack4< red_size, green_size, blue_size, alpha_size >, 3, 0, 1, 2 >;
}

using argb_error = ::color::category::rgb< ::color::category::_internal::argb_error >;
using argb_uint8 = ::color::category::rgb< ::color::category::_internal::argb_uint8 >;
using argb_uint16 = ::color::category::rgb< ::color::category::_internal::argb_uint16 >;
using argb_uint32 = ::color::category::rgb< ::color::category::_internal::argb_uint32 >;
using argb_uint64 = ::color::category::rgb< ::color::category::_internal::argb_uint64 >;
using argb_float = ::color::category::rgb< ::color::category::_internal::argb_float >;
using argb_double = ::color::category::rgb< ::color::category::_internal::argb_double >;
using argb_ldouble = ::color::category::rgb< ::color::category::_internal::argb_ldouble >;

template < unsigned red_size, unsigned green_size, unsigned blue_size, unsigned alpha_size >
using argb_pack = ::color::category::rgb< ::color::category::_internal::argb_pack< red_size, green_size, blue_size, alpha_size > >;

namespace _internal {
using bgr_error = ::color::category::_internal::rgb_scramble< ::color::type::error_t, 2, 1, 0 >;

using bgr_uint8 = ::color::category::_internal::rgb_scramble< std::uint8_t , 2, 1, 0 >;
using bgr_uint16 = ::color::category::_internal::rgb_scramble< std::uint16_t , 2, 1, 0 >;
using bgr_uint32 = ::color::category::_internal::rgb_scramble< std::uint32_t , 2, 1, 0 >;
using bgr_uint64 = ::color::category::_internal::rgb_scramble< std::uint64_t , 2, 1, 0 >;
using bgr_float = ::color::category::_internal::rgb_scramble< float , 2, 1, 0 >;
using bgr_double = ::color::category::_internal::rgb_scramble< double , 2, 1, 0 >;
using bgr_ldouble = ::color::category::_internal::rgb_scramble< long double, 2, 1, 0 >;

template < unsigned red_size, unsigned green_size, unsigned blue_size >
using bgr_pack = ::color::category::_internal::rgb_scramble< ::color::type::pack3< red_size, green_size, blue_size>, 2, 1, 0 >;
}

using bgr_error = ::color::category::rgb< ::color::category::_internal::bgr_error >;
using bgr_uint8 = ::color::category::rgb< ::color::category::_internal::bgr_uint8 >;
using bgr_uint16 = ::color::category::rgb< ::color::category::_internal::bgr_uint16 >;
using bgr_uint32 = ::color::category::rgb< ::color::category::_internal::bgr_uint32 >;
using bgr_uint64 = ::color::category::rgb< ::color::category::_internal::bgr_uint64 >;
using bgr_float = ::color::category::rgb< ::color::category::_internal::bgr_float >;
using bgr_double = ::color::category::rgb< ::color::category::_internal::bgr_double >;
using bgr_ldouble = ::color::category::rgb< ::color::category::_internal::bgr_ldouble >;

template < unsigned red_size, unsigned green_size, unsigned blue_size >
using bgr_pack = ::color::category::rgb< ::color::category::_internal::bgr_pack< red_size, green_size, blue_size > >;

namespace _internal {
using bgra_error = ::color::category::_internal::rgba_scramble< ::color::type::error_t, 2, 1, 0, 3 >;
using bgra_uint8 = ::color::category::_internal::rgba_scramble< std::uint8_t , 2, 1, 0, 3 >;
using bgra_uint16 = ::color::category::_internal::rgba_scramble< std::uint16_t , 2, 1, 0, 3 >;
using bgra_uint32 = ::color::category::_internal::rgba_scramble< std::uint32_t , 2, 1, 0, 3 >;
using bgra_uint64 = ::color::category::_internal::rgba_scramble< std::uint64_t , 2, 1, 0, 3 >;
using bgra_float = ::color::category::_internal::rgba_scramble< float , 2, 1, 0, 3 >;
using bgra_double = ::color::category::_internal::rgba_scramble< double , 2, 1, 0, 3 >;
using bgra_ldouble = ::color::category::_internal::rgba_scramble< long double, 2, 1, 0, 3 >;

template < unsigned red_size, unsigned green_size, unsigned blue_size, unsigned alpha_size >
using bgra_pack = ::color::category::_internal::rgba_scramble< ::color::type::pack4< red_size, green_size, blue_size, alpha_size>, 2, 1, 0, 3 >;
}

using bgra_error = ::color::category::rgb< ::color::category::_internal::bgra_error >;
using bgra_uint8 = ::color::category::rgb< ::color::category::_internal::bgra_uint8 >;
using bgra_uint16 = ::color::category::rgb< ::color::category::_internal::bgra_uint16 >;
using bgra_uint32 = ::color::category::rgb< ::color::category::_internal::bgra_uint32 >;
using bgra_uint64 = ::color::category::rgb< ::color::category::_internal::bgra_uint64 >;
using bgra_float = ::color::category::rgb< ::color::category::_internal::bgra_float >;
using bgra_double = ::color::category::rgb< ::color::category::_internal::bgra_double >;
using bgra_ldouble = ::color::category::rgb< ::color::category::_internal::bgra_ldouble >;

template < unsigned red_size, unsigned green_size, unsigned blue_size, unsigned alpha_size >
using bgra_pack = ::color::category::rgb< ::color::category::_internal::bgra_pack< red_size, green_size, blue_size, alpha_size > >;

namespace _internal {
using abgr_error = ::color::category::_internal::rgba_scramble< ::color::type::error_t, 3, 2, 1, 0 >;
using abgr_uint8 = ::color::category::_internal::rgba_scramble< std::uint8_t , 3, 2, 1, 0 >;
using abgr_uint16 = ::color::category::_internal::rgba_scramble< std::uint16_t , 3, 2, 1, 0 >;
using abgr_uint32 = ::color::category::_internal::rgba_scramble< std::uint32_t , 3, 2, 1, 0 >;
using abgr_uint64 = ::color::category::_internal::rgba_scramble< std::uint64_t , 3, 2, 1, 0 >;
using abgr_float = ::color::category::_internal::rgba_scramble< float , 3, 2, 1, 0 >;
using abgr_double = ::color::category::_internal::rgba_scramble< double , 3, 2, 1, 0 >;
using abgr_ldouble = ::color::category::_internal::rgba_scramble< long double, 3, 2, 1, 0 >;

template < unsigned red_size, unsigned green_size, unsigned blue_size, unsigned alpha_size >
using abgr_pack = ::color::category::_internal::rgba_scramble< ::color::type::pack4< red_size, green_size, blue_size, alpha_size>, 3, 2, 1, 0 >;
}

using abgr_error = ::color::category::rgb< ::color::category::_internal::abgr_error >;
using abgr_uint8 = ::color::category::rgb< ::color::category::_internal::abgr_uint8 >;
using abgr_uint16 = ::color::category::rgb< ::color::category::_internal::abgr_uint16 >;
using abgr_uint32 = ::color::category::rgb< ::color::category::_internal::abgr_uint32 >;
using abgr_uint64 = ::color::category::rgb< ::color::category::_internal::abgr_uint64 >;
using abgr_float = ::color::category::rgb< ::color::category::_internal::abgr_float >;
using abgr_double = ::color::category::rgb< ::color::category::_internal::abgr_double >;
using abgr_ldouble = ::color::category::rgb< ::color::category::_internal::abgr_ldouble >;

template < unsigned red_size, unsigned green_size, unsigned blue_size, unsigned alpha_size >
using abgr_pack = ::color::category::rgb< ::color::category::_internal::abgr_pack< red_size, green_size, blue_size, alpha_size > >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::rgb_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::rgb_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::rgb_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::rgb_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::rgb_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::rgb_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::rgb_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace category {

template< typename tag_name >
struct yiq {
	typedef void category_name;
};

using yiq_bool = ::color::category::yiq< bool >;
using yiq_uint8 = ::color::category::yiq< std::uint8_t >;
using yiq_uint16 = ::color::category::yiq< std::uint16_t >;

using yiq_uint32 = ::color::category::yiq< std::uint32_t >;

using yiq_uint64 = ::color::category::yiq< std::uint64_t >;
using yiq_float = ::color::category::yiq< float >;
using yiq_double = ::color::category::yiq< double >;
using yiq_ldouble = ::color::category::yiq< long double >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::yiq_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::yiq_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::yiq_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::yiq_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::yiq_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::yiq_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::yiq_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace category {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
struct yuv {
	typedef tag_name tag_type;
};

template< ::color::constant::yuv::reference_enum reference_number > using yuv_uint8 = ::color::category::yuv< std::uint8_t , reference_number >;
template< ::color::constant::yuv::reference_enum reference_number > using yuv_uint16 = ::color::category::yuv< std::uint16_t, reference_number >;

template< ::color::constant::yuv::reference_enum reference_number > using yuv_uint32 = ::color::category::yuv< std::uint32_t, reference_number >;

template< ::color::constant::yuv::reference_enum reference_number > using yuv_uint64 = ::color::category::yuv< std::uint64_t, reference_number >;
template< ::color::constant::yuv::reference_enum reference_number > using yuv_float = ::color::category::yuv< float , reference_number >;
template< ::color::constant::yuv::reference_enum reference_number > using yuv_double = ::color::category::yuv< double , reference_number >;
template< ::color::constant::yuv::reference_enum reference_number > using yuv_ldouble = ::color::category::yuv< long double , reference_number >;

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct cmy< ::color::category::yuv_uint8 <reference_number> > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmy< ::color::category::yuv_uint16 <reference_number> > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmy< ::color::category::yuv_uint32 <reference_number> > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmy< ::color::category::yuv_uint64 <reference_number> > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmy< ::color::category::yuv_float <reference_number> > {
	typedef ::color::category::cmy_float akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmy< ::color::category::yuv_double <reference_number> > {
	typedef ::color::category::cmy_double akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmy< ::color::category::yuv_ldouble<reference_number> > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace category {

template< typename tag_name >
struct YCgCo {
	typedef void category_name;
};

using YCgCo_uint8 = ::color::category::YCgCo< std::uint8_t >;
using YCgCo_uint16 = ::color::category::YCgCo< std::uint16_t >;

using YCgCo_uint32 = ::color::category::YCgCo< std::uint32_t >;

using YCgCo_uint64 = ::color::category::YCgCo< std::uint64_t >;
using YCgCo_float = ::color::category::YCgCo< float >;
using YCgCo_double = ::color::category::YCgCo< double >;
using YCgCo_ldouble = ::color::category::YCgCo< long double >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::YCgCo_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::YCgCo_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::YCgCo_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::YCgCo_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::YCgCo_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::YCgCo_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::YCgCo_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace category {

template< typename tag_name >
struct YDbDr {
	typedef void category_name;
};

using YDbDr_bool = ::color::category::YDbDr< bool >;
using YDbDr_uint8 = ::color::category::YDbDr< std::uint8_t >;
using YDbDr_uint16 = ::color::category::YDbDr< std::uint16_t >;

using YDbDr_uint32 = ::color::category::YDbDr< std::uint32_t >;

using YDbDr_uint64 = ::color::category::YDbDr< std::uint64_t >;
using YDbDr_float = ::color::category::YDbDr< float >;
using YDbDr_double = ::color::category::YDbDr< double >;
using YDbDr_ldouble = ::color::category::YDbDr< long double >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::YDbDr_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::YDbDr_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::YDbDr_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::YDbDr_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::YDbDr_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::YDbDr_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::YDbDr_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace constant {
namespace YPbPr {

enum reference_enum {
	error_entity
	,BT_601_entity
	,BT_709_entity
	,BT_2020_entity
};

}
}
}

namespace color {
namespace category {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
struct YPbPr {
	typedef void category_name;
};

template< ::color::constant::YPbPr::reference_enum reference_number > using YPbPr_uint8 = ::color::category::YPbPr< std::uint8_t , reference_number >;
template< ::color::constant::YPbPr::reference_enum reference_number > using YPbPr_uint16 = ::color::category::YPbPr< std::uint16_t , reference_number >;

template< ::color::constant::YPbPr::reference_enum reference_number > using YPbPr_uint32 = ::color::category::YPbPr< std::uint32_t , reference_number >;

template< ::color::constant::YPbPr::reference_enum reference_number > using YPbPr_uint64 = ::color::category::YPbPr< std::uint64_t , reference_number >;
template< ::color::constant::YPbPr::reference_enum reference_number > using YPbPr_float = ::color::category::YPbPr< float , reference_number >;
template< ::color::constant::YPbPr::reference_enum reference_number > using YPbPr_double = ::color::category::YPbPr< double , reference_number >;
template< ::color::constant::YPbPr::reference_enum reference_number > using YPbPr_ldouble = ::color::category::YPbPr< long double , reference_number >;

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct cmy< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmy< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmy< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmy< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmy< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::cmy_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmy< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::cmy_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmy< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace category {

template< typename tag_name >
struct xyz {
	typedef void category_name;
};

using xyz_bool = ::color::category::xyz< bool >;
using xyz_uint8 = ::color::category::xyz< std::uint8_t >;
using xyz_uint16 = ::color::category::xyz< std::uint16_t >;

using xyz_uint32 = ::color::category::xyz< std::uint32_t >;

using xyz_uint64 = ::color::category::xyz< std::uint64_t >;
using xyz_float = ::color::category::xyz< float >;
using xyz_double = ::color::category::xyz< double >;
using xyz_ldouble = ::color::category::xyz< long double >;

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::xyz_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::xyz_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::xyz_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::xyz_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::xyz_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::xyz_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::xyz_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template< typename category_name >
struct info {
public:

	enum { implemented_entity = false };
	enum { meaningful_entity = false };

};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::cmy_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmy_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmy_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmy_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmy_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmy_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmy_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmy_float >
	: public ::color::_internal::utility::bound::general< float, unsigned > {
};

template< >
struct bound< ::color::category::cmy_double >
	: public ::color::_internal::utility::bound::general< double, unsigned > {
};

template< >
struct bound< ::color::category::cmy_ldouble >
	: public ::color::_internal::utility::bound::general< long double, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmy_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::cmy_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::cmy_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::cmy_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename value_name, typename index_name >
struct array {
public:
	typedef value_name value_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< value_name > utility_trait_type;

	typedef typename utility_trait_type::instance_type instance_type;
	typedef typename utility_trait_type::const_type const_type;
	typedef typename utility_trait_type::return_image_type return_image_type;
	typedef typename utility_trait_type::return_type return_type;
	typedef typename utility_trait_type::input_const_type input_const_type;
	typedef typename utility_trait_type::input_type input_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::cmy_float >
	: public ::color::_internal::utility::component::array< float, unsigned> {
};

template< >
struct component< ::color::category::cmy_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::cmy_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::cmy_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::cmy_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::cmy_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::cmy_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template< typename value_name, unsigned length >
struct array {
public:
	typedef value_name value_type;

	typedef std::array< value_name, length> instance_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type & return_original_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< typename instance_type::size_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::const_type index_const_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitC< value_name > component_trait_type;

	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	enum { size_entity = length };

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		return container[index];
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		return container[index];
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		container[index] = value;
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		container[index] = value;
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = length;
		return local_length;
	}
};
}
}
}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::cmy_float >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< >
struct container< ::color::category::cmy_double >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< >
struct container< ::color::category::cmy_ldouble >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::cmy_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< >
struct container< ::color::category::cmy_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< >
struct container< ::color::category::cmy_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< >
struct container< ::color::category::cmy_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {

template< typename type_name >
using cmy = ::color::model< ::color::category::cmy< type_name > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct cyan< ::color::category::cmy< tag_name > > {
public:
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct yellow< ::color::category::cmy< tag_name > > {
public:
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct magenta< ::color::category::cmy< tag_name > > {
public:
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace trait {

template< typename tag_name >
struct index< ::color::category::rgb< tag_name> >
	: public ::color::_internal::utility::type::index< unsigned > {
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct red< ::color::category::rgb< tag_name > > {
public:
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
struct red< ::color::category::rgb< ::color::category::_internal::rgb_scramble< value_name, red_position, green_position, blue_position > > > {
public:
	typedef ::color::category::_internal::rgb_scramble< value_name, red_position, green_position, blue_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = red_position };

	static index_instance_type position() {
		return position_enum;
	}
};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
struct red< ::color::category::rgb< ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > > > {
public:
	typedef ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = red_position };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct green< ::color::category::rgb< tag_name > > {
public:
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
struct green< ::color::category::rgb< ::color::category::_internal::rgb_scramble< value_name, red_position, green_position, blue_position > > > {
public:
	typedef ::color::category::_internal::rgb_scramble< value_name, red_position, green_position, blue_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = green_position };

	static index_instance_type position() {
		return position_enum;
	}
};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
struct green< ::color::category::rgb< ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > > > {
public:
	typedef ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = green_position };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct blue< ::color::category::rgb< tag_name > > {
public:
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
struct blue< ::color::category::rgb< ::color::category::_internal::rgb_scramble< value_name, red_position, green_position, blue_position > > > {
public:
	typedef ::color::category::_internal::rgb_scramble< value_name, red_position, green_position, blue_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = blue_position };

	static index_instance_type position() {
		return position_enum;
	}
};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
struct blue< ::color::category::rgb< ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > > > {
public:
	typedef ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = blue_position };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
struct alpha< ::color::category::rgb< ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > > > {
public:
	typedef ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = alpha_position };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::cmy_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::cmy_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::cmy_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::cmy_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::cmy_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::cmy_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::cmy_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_float >
	: public ::color::_internal::utility::component::array< float, unsigned> {
};

template< >
struct component< ::color::category::rgb_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::rgb_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::rgb_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::rgb_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::rgb_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< typename value_name, unsigned first_position, unsigned second_position, unsigned third_position >
struct component< ::color::category::rgb< ::color::category::_internal::rgb_scramble< value_name, first_position, second_position, third_position > > >
	: public ::color::_internal::utility::component::array< value_name, unsigned > {
};

}
}
namespace color {
namespace trait {

template< typename value_name, unsigned first_position, unsigned second_position, unsigned third_position , unsigned forth_position >
struct component< ::color::category::rgb< ::color::category::_internal::rgba_scramble< value_name, first_position, second_position, third_position, forth_position > > >
	: public ::color::_internal::utility::component::array< value_name, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace type {

template < typename type_name >
struct traitP {
public:
	typedef type_name instance_type;

	typedef instance_type const const_type;

	typedef instance_type const return_image_type;
	typedef instance_type return_type;

	typedef instance_type const& input_const_type;
	typedef instance_type input_type;

};

}
}
}
}

namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename unsigned_name, typename index_name >
struct Unsigned {
public:
	typedef unsigned_name unsigned_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitP< unsigned_type > utility_trait_type;

	typedef typename utility_trait_type::instance_type instance_type;
	typedef typename utility_trait_type::const_type const_type;
	typedef typename utility_trait_type::return_image_type return_image_type;
	typedef typename utility_trait_type::return_type return_type;
	typedef typename utility_trait_type::input_const_type input_const_type;
	typedef typename utility_trait_type::input_type input_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
};

}
}
}
}

namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename index_name >
struct pack8
	: public ::color::_internal::utility::component::Unsigned< std::uint8_t, index_name > {
};

template< typename index_name > using split2222_t = ::color::_internal::utility::component::pack8<index_name>;

template< typename index_name > using split233_t = ::color::_internal::utility::component::pack8<index_name>;
template< typename index_name > using split323_t = ::color::_internal::utility::component::pack8<index_name>;
template< typename index_name > using split332_t = ::color::_internal::utility::component::pack8<index_name>;

template< typename index_name > using split224_t = ::color::_internal::utility::component::pack8<index_name>;
template< typename index_name > using split242_t = ::color::_internal::utility::component::pack8<index_name>;
template< typename index_name > using split422_t = ::color::_internal::utility::component::pack8<index_name>;

}
}
}
}
namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename index_name >
struct pack16
	: public ::color::_internal::utility::component::Unsigned< std::uint8_t, index_name > {
};

template< typename index_name > using split556_t = ::color::_internal::utility::component::pack16<index_name>;
template< typename index_name > using split565_t = ::color::_internal::utility::component::pack16<index_name>;
template< typename index_name > using split655_t = ::color::_internal::utility::component::pack16<index_name>;

template< typename index_name > using split772_t = ::color::_internal::utility::component::pack16<index_name>;
template< typename index_name > using split727_t = ::color::_internal::utility::component::pack16<index_name>;
template< typename index_name > using split277_t = ::color::_internal::utility::component::pack16<index_name>;

template< typename index_name > using split4444_t = ::color::_internal::utility::component::pack16<index_name>;

template< typename index_name > using split5551_t = ::color::_internal::utility::component::pack16<index_name>;
template< typename index_name > using split1555_t = ::color::_internal::utility::component::pack16<index_name>;

}
}
}
}
namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename index_name >
struct pack32
	: public ::color::_internal::utility::component::Unsigned< std::uint16_t, index_name > {
};

template< typename index_name > using split8888_t = ::color::_internal::utility::component::pack32<index_name>;

template< typename index_name > using splitAAA2_t = ::color::_internal::utility::component::pack32<index_name>;
template< typename index_name > using split2AAA_t = ::color::_internal::utility::component::pack32<index_name>;

}
}
}
}
namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename index_name >
struct pack64
	: public ::color::_internal::utility::component::Unsigned< std::uint32_t, index_name > {
};

template< typename index_name > using splitGGGG_t = ::color::_internal::utility::component::pack64<index_name>;
}
}
}
}

namespace color {
namespace trait {

namespace _internal {
namespace rgb {

template< unsigned size_size >
struct pick_component3 {
	typedef ::color::type::error_t component_type;
};

template<>
struct pick_component3<8> {
	typedef unsigned index_type;
	typedef ::color::_internal::utility::component::pack8< index_type > component_type;
};

template<>
struct pick_component3<16> {
	typedef unsigned index_type;

	typedef ::color::_internal::utility::component::pack16< index_type > component_type;
};

template<>
struct pick_component3<32> {
	typedef unsigned index_type;
	typedef ::color::_internal::utility::component::pack32< index_type > component_type;
};

template<>
struct pick_component3<64> {
	typedef unsigned index_type;
	typedef ::color::_internal::utility::component::pack64< index_type > component_type;
};

}
}

template
<
	unsigned first_index, unsigned first_size,
	unsigned second_index, unsigned second_size,
	unsigned third_index, unsigned third_size
	>
struct component< ::color::category::rgb< ::color::category::_internal::rgb_scramble< ::color::type::pack3< first_size, second_size, third_size >, first_index, second_index, third_index > > >
	: public ::color::trait::_internal::rgb::pick_component3< first_size + second_size + third_size >::component_type {
};

}
}

namespace color {
namespace trait {

namespace _internal {
namespace rgb {

template< unsigned size_size >
struct pick_component4 {
	typedef ::color::type::error_t component_type;
};

template<>
struct pick_component4<8> {
	typedef typename ::color::_internal::utility::type::index< unsigned >::instance_type index_type;

	typedef ::color::_internal::utility::component::pack8< index_type > component_type;
};

template<>
struct pick_component4<16> {
	typedef typename ::color::_internal::utility::type::index< unsigned >::instance_type index_type;

	typedef ::color::_internal::utility::component::pack16< index_type > component_type;
};

template<>
struct pick_component4<32> {
	typedef typename ::color::_internal::utility::type::index< unsigned >::instance_type index_type;

	typedef ::color::_internal::utility::component::pack32< index_type > component_type;
};

template<>
struct pick_component4<64> {
	typedef typename ::color::_internal::utility::type::index< unsigned >::instance_type index_type;

	typedef ::color::_internal::utility::component::pack64< index_type > component_type;
};

}
}

template
<
	unsigned first_index, unsigned first_size,
	unsigned second_index, unsigned second_size,
	unsigned third_index, unsigned third_size,
	unsigned fourth_index, unsigned fourth_size
	>
struct component< ::color::category::rgb< ::color::category::_internal::rgba_scramble< ::color::type::pack4< first_size, second_size, third_size, fourth_size >, first_index, second_index, third_index, fourth_index > > >
	: public ::color::trait::_internal::rgb::pick_component4< first_size + second_size + third_size + fourth_size >::component_type {
};

}
}

namespace color {
namespace operation {
namespace _internal {

template< typename category_name>
struct invert {
public:
	typedef category_name category_type;

	typedef ::color::trait::index<category_type> index_trait_type;
	typedef ::color::trait::bound<category_type> bound_type;
	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::container< category_name > container_trait_type;

	typedef typename ::color::model<category_type> model_type;

	typedef typename component_trait_type::input_const_type component_input_const_type;
	typedef typename component_trait_type::return_type component_return_type;

	typedef typename index_trait_type::instance_type index_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	static component_return_type
	component
	(
		component_input_const_type component
		,index_input_const_type index
	) {
		return bound_type::range(index) - component;
	}

	template< index_type index_size >
	static
	component_return_type
	component(component_input_const_type component) {
		return bound_type::template range<index_size>() - component;
	}

	static model_type & process(model_type &result) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, component(result.get(index), index));
		}
		return result;
	}

	static model_type & process(model_type &result, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, component(right.get(index), index));
		}
		return result;
	}

};
}

template< typename category_name >
::color::model<category_name> &
invert
(
	::color::model<category_name> & result
) {
	return ::color::operation::_internal::invert<category_name>::process(result);
}

template< typename category_name >
::color::model<category_name> &
invert
(
	::color::model<category_name> & result
	,::color::model<category_name> const& right
) {
	return ::color::operation::_internal::invert<category_name>::process(result, right);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::return_type
red(::color::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	enum { cyan_p = ::color::place::_internal::cyan<category_type>::position_enum };
	typedef ::color::operation::_internal::invert< category_type > invert_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<red_p,cyan_p>(invert_type::template component<cyan_p>(color_parameter.template get<cyan_p>()));
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::return_type
green(::color::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	enum { yellow_p = ::color::place::_internal::yellow<category_type>::position_enum };
	typedef ::color::operation::_internal::invert< category_type > invert_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<green_p,yellow_p>(invert_type::template component<yellow_p>(color_parameter.template get<yellow_p>()));
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::return_type
blue(::color::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	enum { magenta_p = ::color::place::_internal::magenta<category_type>::position_enum };
	typedef ::color::operation::_internal::invert< category_type > invert_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<blue_p,magenta_p>(invert_type::template component<magenta_p>(color_parameter.template get<magenta_p>()));
}

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::cmy_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::cmy_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::cmy_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::cmy_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::cmy_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::cmy_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::cmy_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yiq_float >
	: public ::color::_internal::utility::component::array< float, unsigned> {
};

template< >
struct component< ::color::category::yiq_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::yiq_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yiq_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::yiq_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::yiq_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::yiq_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace constant {

template< typename category_name>
struct yiq {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::yiq<category_type> this_type;

	static scalar_type const a11() {
		return 1.0000000000000000000;
	}
	static scalar_type const a12() {
		return 0.9562948323208939905;
	}
	static scalar_type const a13() {
		return 0.6210251254447287141;
	}
	static scalar_type const a21() {
		return 1.0000000000000000000;
	}
	static scalar_type const a22() {
		return -0.2721214740839773195;
	}
	static scalar_type const a23() {
		return -0.6473809535176157222;
	}
	static scalar_type const a31() {
		return 1.0000000000000000000;
	}
	static scalar_type const a32() {
		return -1.1069899085671282160;
	}
	static scalar_type const a33() {
		return 1.7046149754988293290;
	}

	static scalar_type const b11() {
		return 0.2990000000000000000;
	}
	static scalar_type const b12() {
		return 0.5870000000000000000;
	}
	static scalar_type const b13() {
		return 0.1140000000000000000;
	}
	static scalar_type const b21() {
		return 0.5957161349127745527;
	}
	static scalar_type const b22() {
		return -0.2744528378392564636;
	}
	static scalar_type const b23() {
		return -0.3212632970735180890;
	}
	static scalar_type const b31() {
		return 0.2114564021201178664;
	}
	static scalar_type const b32() {
		return -0.5225910452916111683;
	}
	static scalar_type const b33() {
		return 0.3111346431714933019;
	}

	static scalar_type const i_min() {
		return -0.5957161349127745527;
	}
	static scalar_type const i_max() {
		return 0.5957161349127745527;
	}
	static scalar_type const i_range() {
		return 2*0.5957161349127745527;
	}

	static scalar_type const q_min() {
		return - 0.5225910452916111683;
	}
	static scalar_type const q_max() {
		return 0.5225910452916111683;
	}
	static scalar_type const q_range() {
		return 2*0.5225910452916111683;
	}

	static scalar_type i_diverse(scalar_type const& normal) {
		return this_type::i_range() * normal + this_type::i_min();
	}
	static scalar_type i_normalize(scalar_type const& divert) {
		return (divert - this_type::i_min()) /this_type::i_range();
	}

	static scalar_type q_diverse(scalar_type const& normal) {
		return this_type::q_range() * normal + this_type::q_min();
	}
	static scalar_type q_normalize(scalar_type const& divert) {
		return (divert - this_type::q_min()) /this_type::q_range();
	}
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::yiq< ::color::category::cmy< tag_name > >::akin_type >::return_type
inphase(::color::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::yiq<category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::yiq< akin_type > yiq_const_type;
	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
	};
	scalar_type value =
		+ yiq_const_type::b21() * (1 - normalize_type::template process< cyan_p>(color_parameter.template get< cyan_p>()))
		+ yiq_const_type::b22() * (1 - normalize_type::template process<magenta_p>(color_parameter.template get<magenta_p>()))
		+ yiq_const_type::b23() * (1 - normalize_type::template process< yellow_p>(color_parameter.template get< yellow_p>()))
		;
	value = yiq_const_type::i_normalize(value);
	return diverse_type::template process<1>(value);
}

}
}

namespace color {
namespace get {

template< typename tag_name>
inline
typename ::color::model< typename ::color::akin::yiq< ::color::category::cmy< tag_name > >::akin_type >::component_const_type
quadrature(::color::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::yiq<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::yiq< akin_type > yiq_const_type;
	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
	};
	scalar_type value =
		+ yiq_const_type::b31() * (1 - normalize_type::template process< cyan_p>(color_parameter.template get< cyan_p>()))
		+ yiq_const_type::b32() * (1 - normalize_type::template process<magenta_p>(color_parameter.template get<magenta_p>()))
		+ yiq_const_type::b33() * (1 - normalize_type::template process< yellow_p>(color_parameter.template get< yellow_p>()))
		;
	value = yiq_const_type::q_normalize(value);
	return diverse_type::template process<2>(value);
}

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::cmy_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::cmy_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::cmy_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::cmy_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::cmy_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::cmy_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::cmy_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_bool >
	: public ::color::_internal::utility::component::array< bool, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_float >
	: public ::color::_internal::utility::component::array< float, unsigned > {
};

template< >
struct component< ::color::category::gray_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::gray_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_uint8 >
	: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::gray_uint16 >
	: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::gray_uint32 >
	: public ::color::_internal::utility::component::Unsigned< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::gray_uint64 >
	: public ::color::_internal::utility::component::Unsigned< std::uint64_t, unsigned> {
};

}
}

namespace color {
namespace constant {

template< typename category_name >
struct gray {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::gray<category_type> this_type;

	static scalar_type const Rc() {
		return 0.2126729;
	}
	static scalar_type const Gc() {
		return 0.7151522;
	}
	static scalar_type const Bc() {
		return 0.0721750;
	}
};

}
}
namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::cmy<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
	};
	scalar_type value =
		gray_const_type::Rc() * (1 - normalize_type::template process< cyan_p>(color_parameter.template get< cyan_p>()))
		+ gray_const_type::Gc() * (1 - normalize_type::template process<magenta_p>(color_parameter.template get<magenta_p>()))
		+ gray_const_type::Bc() * (1 - normalize_type::template process< yellow_p>(color_parameter.template get< yellow_p>()));
	return diverse_type::template process<0>(value);
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::cmy< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef ::color::operation::_internal::invert< akin_type > invert_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	enum { cyan_p = ::color::place::_internal::cyan<category_type>::position_enum };
	color_parameter.template set<cyan_p>(reformat_type::template process<cyan_p,cyan_p>(invert_type::template component<cyan_p>(component_parameter)));
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::cmy< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef ::color::operation::_internal::invert< akin_type > invert_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	enum { yellow_p = ::color::place::_internal::yellow<category_type>::position_enum };
	color_parameter.template set<yellow_p>(reformat_type::template process<yellow_p,yellow_p>(invert_type::template component<yellow_p>(component_parameter)));
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::cmy< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef ::color::operation::_internal::invert< akin_type > invert_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	enum { magenta_p = ::color::place::_internal::magenta<category_type>::position_enum };
	color_parameter.template set<magenta_p>(reformat_type::template process<magenta_p,magenta_p>(invert_type::template component<magenta_p>(component_parameter)));
}

}
}

namespace color {
namespace operation {
namespace _internal {
template< typename category_name >
struct scale {
public:
	typedef category_name category_type;
	typedef typename ::color::trait::scalar<category_name>::input_const_type scalar_const_input_type;

	typedef ::color::trait::container< category_type > container_trait_type;

	typedef ::color::trait::index<category_type> index_trait_type;

	typedef typename ::color::model<category_type> model_type;

	typedef model_type & model_input_type;
	typedef model_type const& model_const_input_type;

	typedef typename index_trait_type::instance_type index_type;

	static model_type & process(model_input_type result, scalar_const_input_type const& scalar) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, result.get(index) * scalar);
		}
		return result;
	}

	static model_type & process(model_input_type result, scalar_const_input_type scalar, model_const_input_type right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, scalar * right.get(index));
		}
		return result;
	}

};
}

template< typename category_name >
::color::model<category_name> & scale
(
	::color::model<category_name> & result
	,typename ::color::trait::scalar<category_name>::input_const_type scalar
) {
	return ::color::operation::_internal::scale<category_name>::process(result, scalar);
}

template< typename category_name >
::color::model<category_name> & scale
(
	::color::model<category_name> & result
	,typename ::color::trait::scalar<category_name>::input_const_type scalar
	,::color::model<category_name> const& right
) {
	return ::color::operation::_internal::scale<category_name>::process(result, scalar, right);
}

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::rgb_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::rgb_uint16 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::rgb_uint32 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::rgb_uint64 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::rgb_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::rgb_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::rgb_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::cmy<tag_name> > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray<::color::category::cmy<tag_name> >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::normalize< category_type > normalize_cmy_type;
	typedef ::color::_internal::normalize< akin_type > normalize_akin_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
	};
	scalar_type value =
		gray_const_type::Rc() * (scalar_type(1) - normalize_cmy_type::template process< cyan_p>(color_parameter.template get< cyan_p>()))
		+ gray_const_type::Gc() * (scalar_type(1) - normalize_cmy_type::template process<magenta_p>(color_parameter.template get<magenta_p>()))
		+ gray_const_type::Bc() * (scalar_type(1) - normalize_cmy_type::template process< yellow_p>(color_parameter.template get< yellow_p>()));
	value = normalize_akin_type::template process<0>(component_parameter) / value;
	::color::operation::scale(color_parameter, scalar_type(1) - value);
}

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct gray< ::color::category::gray< tag_name > > {
public:
	typedef ::color::category::gray< tag_name > akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::cmyk_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::cmyk_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::cmyk_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::cmyk_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::cmyk_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::cmyk_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::cmyk_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::hsl_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::hsl_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::hsl_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::hsl_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::hsl_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::hsl_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::hsl_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::hsv_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::hsv_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::hsv_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::hsv_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::hsv_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::hsv_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::hsv_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::hsi_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::hsi_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::hsi_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::hsi_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::hsi_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::hsi_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::hsi_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::yiq_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::yiq_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::yiq_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::yiq_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::yiq_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::yiq_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::yiq_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct gray< ::color::category::yuv_uint8 <reference_number> > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct gray< ::color::category::yuv_uint16 <reference_number> > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct gray< ::color::category::yuv_uint32 <reference_number> > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct gray< ::color::category::yuv_uint64 <reference_number> > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct gray< ::color::category::yuv_float <reference_number> > {
	typedef ::color::category::gray_float akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct gray< ::color::category::yuv_double <reference_number> > {
	typedef ::color::category::gray_double akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct gray< ::color::category::yuv_ldouble<reference_number> > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::YCgCo_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::YCgCo_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::YCgCo_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::YCgCo_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::YCgCo_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::YCgCo_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::YCgCo_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::YDbDr_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::YDbDr_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::YDbDr_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::YDbDr_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::YDbDr_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::YDbDr_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::YDbDr_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct gray< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct gray< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct gray< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct gray< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct gray< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::gray_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct gray< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::gray_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct gray< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::xyz_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::xyz_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::xyz_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::xyz_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::xyz_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::xyz_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::xyz_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::gray_bool > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::gray_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::gray_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::gray_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::gray_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::gray_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::gray_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::gray_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_bool >
	: public ::color::_internal::utility::bound::general< bool, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_float >
	: public ::color::_internal::utility::bound::general< float, unsigned > {
};

template< >
struct bound< ::color::category::gray_double >
	: public ::color::_internal::utility::bound::general< double, unsigned > {
};

template< >
struct bound< ::color::category::gray_ldouble >
	: public ::color::_internal::utility::bound::general< long double, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::gray_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::gray_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::gray_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template< typename index_name >
struct boolean {
public:
	typedef index_name index_type;
	typedef bool value_type;

	typedef bool instance_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type & return_original_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;

	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitC< value_type > component_trait_type;

	typedef typename component_trait_type::instance_type component_type;

	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	enum { size_entity = 1 };

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		return container;
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		return container;
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		container = value;
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		container = value;
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = 1;
		return local_length;
	}
};
}
}
}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_bool >
	: public ::color::_internal::utility::container::boolean< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_float >
	: public ::color::_internal::utility::container::array< float, 1 > {
};

template< >
struct container< ::color::category::gray_ldouble >
	: public ::color::_internal::utility::container::array< long double, 1 > {
};

template< >
struct container< ::color::category::gray_double >
	: public ::color::_internal::utility::container::array< double, 1 > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template< typename unsigned_name, typename value_name, typename index_name, unsigned length, unsigned width >
struct Unsigned {
public:
	typedef unsigned_name unsigned_type;
	typedef value_name value_type;
	typedef index_name index_type;
	typedef unsigned_name instance_type;

	typedef ::color::_internal::utility::container::Unsigned<unsigned_name,value_name,index_name,length,width> this_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type & return_original_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitP< value_name > component_trait_type;

	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	enum { size_entity = length };

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		return (component_type)((container >> (index * width)) & mask());
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		return (component_type)((container >> (index * width)) & mask());
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		container = (container & ~(this_type::mask() << (index * width))) | ((instance_type(value) << (index * width)));
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		container = (container & ~(this_type::mask() << (index * width))) | ((instance_type(value)) << (index * width));
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = length;
		return local_length;
	}
private:
	static return_image_type mask() {
		static instance_type local_mask = (((instance_type(1) << (width-1)) - instance_type(1))<< 1) + instance_type(1);
		return local_mask;
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_uint8 >
	: public ::color::_internal::utility::container::Unsigned< std::uint8_t, std::uint8_t, unsigned, 1, 8 > {
};

template< >
struct container< ::color::category::gray_uint16 >
	: public ::color::_internal::utility::container::Unsigned< std::uint16_t, std::uint16_t, unsigned, 1, 16 > {
};

template< >
struct container< ::color::category::gray_uint32 >
	: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint32_t, unsigned, 1, 32 > {
};

template< >
struct container< ::color::category::gray_uint64 >
	: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint64_t, unsigned, 1, 64 > {
};

}
}

namespace color {

template< typename type_name >
using gray = ::color::model< ::color::category::gray< type_name > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct gray< ::color::category::gray< tag_name > > {
public:
	typedef ::color::category::gray< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::gray_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::gray_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::gray_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::gray_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::gray_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::gray_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::gray_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::gray<tag_name> >::akin_type >::return_type
red(::color::model< ::color::category::gray<tag_name> > const& color_parameter) {
	typedef ::color::category::gray<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<red_p,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::gray<tag_name> >::akin_type >::return_type
green(::color::model< ::color::category::gray<tag_name> > const& color_parameter) {
	typedef ::color::category::gray<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<green_p,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::gray<tag_name> >::akin_type >::return_type
blue(::color::model< ::color::category::gray<tag_name> > const& color_parameter) {
	typedef ::color::category::gray<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<blue_p,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name >
typename ::color::trait::component< ::color::category::gray<tag_name> >::return_type
gray(::color::model< ::color::category::gray<tag_name> > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::gray< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::gray< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::gray<tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::reformat<category_type, akin_type, scalar_type > reformat_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	enum { gray_p = ::color::place::_internal::gray<category_type>::position_enum };
	color_parameter.template set<gray_p>(reformat_type::template process<gray_p,red_p>(component_parameter));
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::gray< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::gray< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::gray<tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::reformat<category_type, akin_type, scalar_type > reformat_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	enum { gray_p = ::color::place::_internal::gray<category_type>::position_enum };
	color_parameter.template set<gray_p>(reformat_type::template process<gray_p,green_p>(component_parameter));
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::gray< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::gray< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::gray<tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::reformat<category_type, akin_type, scalar_type > reformat_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	enum { gray_p = ::color::place::_internal::gray<category_type>::position_enum };
	color_parameter.template set<gray_p>(reformat_type::template process<gray_p,blue_p>(component_parameter));
}

}
}

namespace color {
namespace set {
template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::gray< tag_name > > & color_parameter,
	typename ::color::model< ::color::category::gray< tag_name > >::component_input_const_type component_parameter
) {
	typedef ::color::category::gray< tag_name > category_type;
	enum { gray_p = ::color::place::_internal::gray< category_type >::position_enum };
	color_parameter.template set<gray_p>(component_parameter);
}

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::gray< tag_left_name >
	,::color::category::gray< tag_right_name>
	> {
public:
	typedef ::color::category::gray< tag_left_name > category_left_type;
	typedef ::color::category::gray< tag_right_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		gl = ::color::place::_internal::gray<category_left_type>::position_enum
		,gr = ::color::place::_internal::gray<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<gl>(left, reformat_type::template process<gl,gr>(container_right_trait_type::template get<gr>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::cmy<cmy_tag_name>
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::cmy<cmy_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::gray< category_left_type > gray_const_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type value =
			gray_const_type::Rc() * (1 - normalize_type::template process< cyan_p> (container_right_trait_type::template get< cyan_p>(right)))
			+ gray_const_type::Gc() * (1 - normalize_type::template process<magenta_p> (container_right_trait_type::template get<magenta_p>(right)))
			+ gray_const_type::Bc() * (1 - normalize_type::template process< yellow_p> (container_right_trait_type::template get< yellow_p>(right)));
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(value));
	}
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::gray_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::gray_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::gray_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::gray_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::gray_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::gray_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::gray_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::cmy_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::cmy_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::cmy_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::cmy_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::cmy_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::cmy_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::cmy_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct cmyk< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::hsl_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::hsl_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::hsl_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::hsl_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::hsl_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::hsl_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::hsl_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::hsv_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::hsv_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::hsv_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::hsv_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::hsv_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::hsv_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::hsv_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::hsi_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::hsi_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::hsi_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::hsi_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::hsi_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::hsi_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::hsi_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::rgb_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::rgb_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::rgb_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::rgb_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::rgb_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::rgb_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::rgb_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::yiq_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::yiq_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::yiq_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::yiq_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::yiq_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::yiq_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::yiq_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct cmyk< ::color::category::yuv_uint8 < reference_number > > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmyk< ::color::category::yuv_uint16 < reference_number > > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmyk< ::color::category::yuv_uint32 < reference_number > > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmyk< ::color::category::yuv_uint64 < reference_number > > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmyk< ::color::category::yuv_float < reference_number > > {
	typedef ::color::category::cmyk_float akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmyk< ::color::category::yuv_double < reference_number > > {
	typedef ::color::category::cmyk_double akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct cmyk< ::color::category::yuv_ldouble< reference_number > > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::YCgCo_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::YCgCo_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::YCgCo_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::YCgCo_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::YCgCo_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::YCgCo_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::YCgCo_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::YDbDr_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::YDbDr_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::YDbDr_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::YDbDr_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::YDbDr_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::YDbDr_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::YDbDr_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct cmyk< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmyk< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmyk< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmyk< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmyk< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::cmyk_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmyk< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::cmyk_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct cmyk< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmyk< ::color::category::xyz_uint8 > {
	typedef ::color::category::cmyk_uint8 akin_type;
};
template< >struct cmyk< ::color::category::xyz_uint16 > {
	typedef ::color::category::cmyk_uint16 akin_type;
};
template< >struct cmyk< ::color::category::xyz_uint32 > {
	typedef ::color::category::cmyk_uint32 akin_type;
};
template< >struct cmyk< ::color::category::xyz_uint64 > {
	typedef ::color::category::cmyk_uint64 akin_type;
};
template< >struct cmyk< ::color::category::xyz_float > {
	typedef ::color::category::cmyk_float akin_type;
};
template< >struct cmyk< ::color::category::xyz_double > {
	typedef ::color::category::cmyk_double akin_type;
};
template< >struct cmyk< ::color::category::xyz_ldouble > {
	typedef ::color::category::cmyk_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::cmyk_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmyk_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmyk_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmyk_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmyk_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmyk_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::cmyk_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmyk_float >
	: public ::color::_internal::utility::bound::general< float, unsigned > {
};

template< >
struct bound< ::color::category::cmyk_double >
	: public ::color::_internal::utility::bound::general< double, unsigned > {
};

template< >
struct bound< ::color::category::cmyk_ldouble >
	: public ::color::_internal::utility::bound::general< long double, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmyk_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::cmyk_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::cmyk_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::cmyk_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::cmyk_float >
	: public ::color::_internal::utility::component::array< float, unsigned> {
};

template< >
struct component< ::color::category::cmyk_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::cmyk_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::cmyk_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::cmyk_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::cmyk_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::cmyk_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::cmyk_float >
	: public ::color::_internal::utility::container::array< float, 4 > {
};

template< >
struct container< ::color::category::cmyk_double >
	: public ::color::_internal::utility::container::array< double, 4 > {
};

template< >
struct container< ::color::category::cmyk_ldouble >
	: public ::color::_internal::utility::container::array< long double, 4 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::cmyk_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 4 > {
};

template< >
struct container< ::color::category::cmyk_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 4 > {
};

template< >
struct container< ::color::category::cmyk_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 4 > {
};

template< >
struct container< ::color::category::cmyk_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 4 > {
};

}
}

namespace color {

template< typename type_name >
using cmyk = ::color::model< ::color::category::cmyk< type_name > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct cyan< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct magenta< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct yellow< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct key< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 3 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace check {
namespace _internal {
namespace _privateCMYK {

template< typename category_name >
struct integrity {
public:
	typedef category_name category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::scalar< category_type > scalar_trait_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
		, key_p = ::color::place::_internal::key<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<key_p>() == bound_type::template maximum<key_p>()) {
			return false;
		}
		if(m.template get< cyan_p>() == bound_type::template minimum< cyan_p>()) {
			return true;
		}
		if(m.template get<magenta_p>() == bound_type::template minimum<magenta_p>()) {
			return true;
		}
		if(m.template get< yellow_p>() == bound_type::template minimum< yellow_p>()) {
			return true;
		}
		return false;
	}
};

}

template< > struct integrity< ::color::category::cmyk_uint8 > : public ::color::check::_internal::_privateCMYK::integrity< ::color::category::cmyk_uint8 > { };
template< > struct integrity< ::color::category::cmyk_uint16 > : public ::color::check::_internal::_privateCMYK::integrity< ::color::category::cmyk_uint16 > { };
template< > struct integrity< ::color::category::cmyk_uint32 > : public ::color::check::_internal::_privateCMYK::integrity< ::color::category::cmyk_uint32 > { };
template< > struct integrity< ::color::category::cmyk_uint64 > : public ::color::check::_internal::_privateCMYK::integrity< ::color::category::cmyk_uint64 > { };

template<>
struct integrity< ::color::category::cmyk_float> {
public:
	typedef ::color::category::cmyk_float category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::scalar< category_type > scalar_trait_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
		, key_p = ::color::place::_internal::key<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<key_p>() == bound_type::template maximum<key_p>()) {
			return false;
		}
		if(true == scalar_trait_type::is_small(m.template get< cyan_p>() - bound_type::template minimum< cyan_p>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get<magenta_p>() - bound_type::template minimum<magenta_p>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get< key_p>() - bound_type::template minimum< key_p>())) {
			return true;
		}
		return false;
	}
};

template<>
struct integrity< ::color::category::cmyk_double > {
public:
	typedef ::color::category::cmyk_double category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::scalar< category_type > scalar_trait_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
		, key_p = ::color::place::_internal::key<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<key_p>() == bound_type::template maximum<key_p>()) {
			return false;
		}
		if(true == scalar_trait_type::is_small(m.template get< cyan_p>() - bound_type::template minimum< cyan_p>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get<magenta_p>() - bound_type::template minimum<magenta_p>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get< key_p>() - bound_type::template minimum< key_p>())) {
			return true;
		}
		return false;
	}
};

template<>
struct integrity< ::color::category::cmyk_ldouble > {
public:
	typedef ::color::category::cmyk_ldouble category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::scalar< category_type > scalar_trait_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
		, key_p = ::color::place::_internal::key<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<key_p>() == bound_type::template maximum<key_p>()) {
			return false;
		}
		if(true == scalar_trait_type::is_small(m.template get< cyan_p>() - bound_type::template minimum< cyan_p>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get<magenta_p>() - bound_type::template minimum<magenta_p>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get< key_p>() - bound_type::template minimum< key_p>())) {
			return true;
		}
		return false;
	}
};

}
}
}

namespace color {
namespace fix {
namespace _internal {

template< typename tag_name >
struct unique< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound<category_type> bound_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::operation::_internal::invert< category_type > invert_type;
	typedef ::color::_internal::diverse< category_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
		, key_p = ::color::place::_internal::key<category_type>::position_enum
	};

	static void process(model_type &result) {
		if(result.template get<key_p>() == bound_type::template maximum<key_p>()) {
			result.template set<cyan_p>(bound_type::template minimum<cyan_p>());
			result.template set<magenta_p>(bound_type::template minimum<magenta_p>());
			result.template set<yellow_p>(bound_type::template minimum<yellow_p>());
			return ;
		}
		if(result.template get<cyan_p>() == bound_type::template minimum<cyan_p>()) {
			return;
		}
		if(result.template get<magenta_p>() == bound_type::template minimum<magenta_p>()) {
			return;
		}
		if(result.template get<yellow_p>() == bound_type::template minimum<yellow_p>()) {
			return;
		}
		scalar_type cyan = normalize_type::template process<cyan_p>(result.template get<cyan_p>());
		scalar_type key = normalize_type::template process<key_p>(result.template get<key_p>());
		result.template set<cyan_p>(bound_type::template minimum<cyan_p>());
		result.template set<magenta_p>(bound_type::template minimum<magenta_p>());
		result.template set<yellow_p>(bound_type::template minimum<yellow_p>());
		result.template set<key_p>(diverse_type::template process<key_p>((1- (1- cyan)*(1-key))));
	}

	static void process(model_type &result, model_type const& right) {
		if(result.template get<key_p>() == bound_type::template maximum<key_p>()) {
			result.template set<cyan_p>(bound_type::template minimum<cyan_p>());
			result.template set<magenta_p>(bound_type::template minimum<magenta_p>());
			result.template set<yellow_p>(bound_type::template minimum<yellow_p>());
			result.template set<key_p>(bound_type::template maximum<key_p>());
			return ;
		}
		result = right;
		if(result.template get<cyan_p>() == bound_type::template minimum<cyan_p>()) {
			return;
		}
		if(result.template get<magenta_p>() == bound_type::template minimum<magenta_p>()) {
			return;
		}
		if(result.template get<yellow_p>() == bound_type::template minimum<yellow_p>()) {
			return;
		}
		scalar_type cyan = normalize_type::template process<cyan_p>(result.template get<cyan_p>());
		scalar_type key = normalize_type::template process<key_p>(result.template get<key_p>());
		result.template set<cyan_p>(bound_type::template minimum<cyan_p>());
		result.template set<magenta_p>(bound_type::template minimum<magenta_p>());
		result.template set<yellow_p>(bound_type::template minimum<yellow_p>());
		result.template set<key_p>(diverse_type::template process<key_p>((1- (1- cyan)*(1-key))));
	}

};

}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::cmyk<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::cmyk<tag_name> > const& color_parameter) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	enum {
		cyan_p = ::color::place::_internal::cyan<category_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_type>::position_enum
		, key_p = ::color::place::_internal::key<category_type>::position_enum
	};
	scalar_type c = normalize_type::template process< cyan_p>(color_parameter.template get< cyan_p>());
	scalar_type m = normalize_type::template process<magenta_p>(color_parameter.template get<magenta_p>());
	scalar_type y = normalize_type::template process< yellow_p>(color_parameter.template get< yellow_p>());
	scalar_type k = normalize_type::template process< key_p>(color_parameter.template get< key_p>());
	scalar_type value =
		(gray_const_type::Rc() * (scalar_type(1)-c)
		 + gray_const_type::Gc() * (scalar_type(1)-m)
		 + gray_const_type::Bc() * (scalar_type(1)-y)) * (scalar_type(1)-k);
	return diverse_type::template process<0>(value);
}

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::cmyk_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::cmyk_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::cmyk_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::cmyk_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::cmyk_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::cmyk_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::cmyk_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::cmyk< tag_name > >::akin_type >::return_type
red(::color::model< ::color::category::cmyk< tag_name > > const& color_parameter) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	enum { cyan_p = ::color::place::_internal::cyan< category_type >::position_enum };
	enum { key_p = ::color::place::_internal::key< category_type >::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type c = normalize_type::template process< cyan_p >(color_parameter.template get< cyan_p >());
	scalar_type k = normalize_type::template process< key_p >(color_parameter.template get< key_p >());
	scalar_type r = (scalar_type(1)-c) * (scalar_type(1)-k);
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::cmyk< tag_name > >::akin_type >::return_type
green(::color::model< ::color::category::cmyk< tag_name > > const& color_parameter) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	enum { magenta_p = ::color::place::_internal::magenta< category_type >::position_enum };
	enum { key_p = ::color::place::_internal::key< category_type >::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type m = normalize_type::template process< magenta_p >(color_parameter.template get< magenta_p >());
	scalar_type k = normalize_type::template process< key_p >(color_parameter.template get< key_p >());
	scalar_type g = (1-m) * (1-k);
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::cmyk< tag_name > >::akin_type >::return_type
blue(::color::model< ::color::category::cmyk< tag_name > > const& color_parameter) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue< akin_type >::position_enum };
	enum { yellow_p = ::color::place::_internal::yellow< category_type >::position_enum };
	enum { key_p = ::color::place::_internal::key< category_type >::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type y = normalize_type::template process< yellow_p >(color_parameter.template get<yellow_p>());
	scalar_type k = normalize_type::template process< key_p >(color_parameter.template get< key_p >());
	scalar_type b = (1-y) * (1-k);
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::cmyk< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmyk< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<red_p> (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::cmyk< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmyk< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green< akin_type >::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::cmyk< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmyk< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue< akin_type >::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< blue_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::hsl_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::hsl_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::hsl_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::hsl_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::hsl_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::hsl_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::hsl_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::hsv_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::hsv_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::hsv_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::hsv_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::hsv_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::hsv_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::hsv_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::hsi_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::hsi_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::hsi_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::hsi_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::hsi_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::hsi_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::hsi_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct rgb< ::color::category::rgb< tag_name > > {
public:
	typedef ::color::category::rgb< tag_name > akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::yiq_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::yiq_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::yiq_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::yiq_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::yiq_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::yiq_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::yiq_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct rgb< ::color::category::yuv_uint8 <reference_number> > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct rgb< ::color::category::yuv_uint16 <reference_number> > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct rgb< ::color::category::yuv_uint32 <reference_number> > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct rgb< ::color::category::yuv_uint64 <reference_number> > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct rgb< ::color::category::yuv_float <reference_number> > {
	typedef ::color::category::rgb_float akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct rgb< ::color::category::yuv_double <reference_number> > {
	typedef ::color::category::rgb_double akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct rgb< ::color::category::yuv_ldouble <reference_number> > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::YCgCo_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::YCgCo_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::YCgCo_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::YCgCo_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::YCgCo_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::YCgCo_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::YCgCo_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::YDbDr_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::YDbDr_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::YDbDr_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::YDbDr_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::YDbDr_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::YDbDr_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::YDbDr_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct rgb< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct rgb< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct rgb< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct rgb< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct rgb< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::rgb_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct rgb< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::rgb_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct rgb< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::xyz_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::xyz_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::xyz_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::xyz_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::xyz_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::xyz_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::xyz_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::rgb_error > {
public:
	enum { implemented_entity = false };
	enum { meaningful_entity = false };
};
template <> struct info< ::color::category::rgb_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgb_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgb_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgb_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgb_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgb_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgb_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template< unsigned first_size, unsigned second_size, unsigned third_size >
struct info< ::color::category::rgb_pack< first_size, second_size, third_size > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template <> struct info< ::color::category::rgba_error > {
public:
	enum { implemented_entity = false };
	enum { meaningful_entity = false };
};
template <> struct info< ::color::category::rgba_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgba_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgba_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgba_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgba_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgba_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::rgba_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
struct info< ::color::category::rgba_pack< first_size, second_size, third_size, fourth_size > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template <> struct info< ::color::category::argb_error > {
public:
	enum { implemented_entity = false };
	enum { meaningful_entity = false };
};
template <> struct info< ::color::category::argb_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::argb_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::argb_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::argb_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::argb_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::argb_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::argb_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
struct info< ::color::category::argb_pack< first_size, second_size, third_size, fourth_size > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template <> struct info< ::color::category::bgr_error > {
public:
	enum { implemented_entity = false };
	enum { meaningful_entity = false };
};
template <> struct info< ::color::category::bgr_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgr_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgr_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgr_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgr_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgr_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgr_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template< unsigned first_size, unsigned second_size, unsigned third_size >
struct info< ::color::category::bgr_pack< first_size, second_size, third_size > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template <> struct info< ::color::category::bgra_error > {
public:
	enum { implemented_entity = false };
	enum { meaningful_entity = false };
};
template <> struct info< ::color::category::bgra_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgra_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgra_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgra_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgra_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgra_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::bgra_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
struct info< ::color::category::bgra_pack< first_size, second_size, third_size, fourth_size > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template <> struct info< ::color::category::abgr_error > {
public:
	enum { implemented_entity = false };
	enum { meaningful_entity = false };
};
template <> struct info< ::color::category::abgr_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::abgr_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::abgr_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::abgr_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::abgr_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::abgr_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::abgr_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
struct info< ::color::category::abgr_pack< first_size, second_size, third_size, fourth_size > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_float >
	: public ::color::_internal::utility::bound::general< float, unsigned > {
};

template< >
struct bound< ::color::category::rgb_double >
	: public ::color::_internal::utility::bound::general< double, unsigned > {
};

template< >
struct bound< ::color::category::rgb_ldouble >
	: public ::color::_internal::utility::bound::general< long double, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::rgb_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::rgb_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::rgb_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< typename value_name, unsigned first_position, unsigned second_position, unsigned third_position >
struct bound< ::color::category::rgb< ::color::category::_internal::rgb_scramble< value_name, first_position, second_position, third_position > > >
	: public ::color::_internal::utility::bound::general< value_name, unsigned > {
};

}
}
namespace color {
namespace trait {

template< typename value_name, unsigned first_position, unsigned second_position, unsigned third_position, unsigned fourth_position >
struct bound< ::color::category::rgb< ::color::category::_internal::rgba_scramble< value_name, first_position, second_position, third_position,fourth_position > > >
	: public ::color::_internal::utility::bound::general< value_name, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template
<
	typename unsigned_name
	,typename index_name
	,unsigned first_size, unsigned second_size, unsigned third_size
	>
struct pack3 {
public:
	typedef unsigned_name unsigned_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitP< unsigned_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	enum {
		first_max = (1 << first_size) - 1,
		second_max = (1 << second_size) - 1,
		third_max = (1 << third_size) - 1,
	};

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { first_max, second_max, third_max };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { first_max, second_max, third_max };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type value=0;
		return value;
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type value=0;
		return value;
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type max_list[] = { first_max, second_max, third_max };
		return max_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type max_list[] = { first_max, second_max, third_max };
		return max_list[index];
	}
};

template< typename unsigned_name, unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_N_t = ::color::_internal::utility::bound::pack3< unsigned_name, unsigned, first_size, second_size, third_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_8_t = ::color::_internal::utility::bound::pack3_N_t< std::uint8_t, first_size, second_size, third_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_16_t = ::color::_internal::utility::bound::pack3_N_t< std::uint16_t, first_size, second_size, third_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_32_t = ::color::_internal::utility::bound::pack3_N_t< std::uint32_t, first_size, second_size, third_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_64_t = ::color::_internal::utility::bound::pack3_N_t< std::uint64_t, first_size, second_size, third_size >;

using split233_t = ::color::_internal::utility::bound::pack3_8_t< 2, 3, 3 >;
using split323_t = ::color::_internal::utility::bound::pack3_8_t< 3, 2, 3 >;
using split332_t = ::color::_internal::utility::bound::pack3_8_t< 3, 3, 2 >;

using split422_t = ::color::_internal::utility::bound::pack3_8_t< 4, 2, 2 >;
using split242_t = ::color::_internal::utility::bound::pack3_8_t< 2, 4, 2 >;
using split224_t = ::color::_internal::utility::bound::pack3_8_t< 2, 2, 4 >;

using split655_t = ::color::_internal::utility::bound::pack3_16_t< 6, 5, 5 >;
using split565_t = ::color::_internal::utility::bound::pack3_16_t< 5, 6, 5 >;
using split556_t = ::color::_internal::utility::bound::pack3_16_t< 5, 5, 6 >;

}
}
}
}

namespace color {
namespace trait {

namespace _internal {
namespace rgb {

template< unsigned size_size >
struct pick_bound3 {
	typedef ::color::type::error_t bound_type;
};

template<>
struct pick_bound3<8> {
	template< unsigned first_size, unsigned second_size, unsigned third_size >
	using bound_type = ::color::_internal::utility::bound::pack3_8_t< first_size, second_size, third_size >;
};

template<>
struct pick_bound3<16> {
	template< unsigned first_size, unsigned second_size, unsigned third_size >
	using bound_type = ::color::_internal::utility::bound::pack3_16_t< first_size, second_size, third_size >;
};

template<>
struct pick_bound3<32> {
	template< unsigned first_size, unsigned second_size, unsigned third_size >
	using bound_type = ::color::_internal::utility::bound::pack3_32_t< first_size, second_size, third_size >;
};

template<>
struct pick_bound3<64> {
	template< unsigned first_size, unsigned second_size, unsigned third_size >
	using bound_type = ::color::_internal::utility::bound::pack3_64_t< first_size, second_size, third_size >;
};

}
}

template
<
	unsigned first_index, unsigned first_size,
	unsigned second_index, unsigned second_size,
	unsigned third_index, unsigned third_size
	>
struct bound< ::color::category::rgb< ::color::category::_internal::rgb_scramble< ::color::type::pack3< first_size, second_size, third_size >, first_index, second_index, third_index > > >
	: public ::color::trait::_internal::rgb::pick_bound3< first_size + second_size + third_size >:: template bound_type<first_size, second_size, third_size> {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template
<
	typename unsigned_name
	,typename index_name
	,unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size
	>
struct pack4 {
public:
	typedef unsigned_name unsigned_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitP< unsigned_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	enum {
		first_max = (1 << first_size) - 1,
		second_max = (1 << second_size) - 1,
		third_max = (1 << third_size) - 1,
		fourth_max = (1 << fourth_size) - 1,
	};

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { first_max, second_max, third_max, fourth_max };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { first_max, second_max, third_max, fourth_max };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type value=0;
		return value;
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type value=0;
		return value;
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type max_list[] = { first_max, second_max, third_max, fourth_max };
		return max_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type max_list[] = { first_max, second_max, third_max, fourth_max };
		return max_list[index];
	}
};

template< typename unsigned_name, unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_N_t = ::color::_internal::utility::bound::pack4< unsigned_name, unsigned, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_8_t = ::color::_internal::utility::bound::pack4_N_t< std::uint8_t, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_16_t = ::color::_internal::utility::bound::pack4_N_t< std::uint16_t, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_32_t = ::color::_internal::utility::bound::pack4_N_t< std::uint32_t, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_64_t = ::color::_internal::utility::bound::pack4_N_t< std::uint64_t, first_size, second_size, third_size, fourth_size >;

typedef ::color::_internal::utility::bound::pack4_8_t< 2, 2, 2, 2 > split2222_t;

typedef ::color::_internal::utility::bound::pack4_16_t< 4, 4, 4, 4 > split4444_t;
typedef ::color::_internal::utility::bound::pack4_16_t< 6, 6, 6, 6 > split6666_t;

typedef ::color::_internal::utility::bound::pack4_16_t< 1, 5, 5, 5 > split1555_t;
typedef ::color::_internal::utility::bound::pack4_16_t< 5, 5, 5, 1 > split5551_t;

typedef ::color::_internal::utility::bound::pack4_16_t< 6, 6, 6, 6 > split6666_t;

typedef ::color::_internal::utility::bound::pack4_32_t< 8, 8, 8, 8 > split8888_t;

typedef ::color::_internal::utility::bound::pack4_32_t< 0, 10, 10, 2 > splitAAA2_t;
typedef ::color::_internal::utility::bound::pack4_32_t< 2, 10, 10, 10 > split2AAA_t;

typedef ::color::_internal::utility::bound::pack4_32_t< 6, 16, 16, 16 > splitGGGG_t;

}
}
}
}

namespace color {
namespace trait {

namespace _internal {
namespace rgb {

template< unsigned size_size >
struct pick_bound4 {
	typedef ::color::type::error_t bound_type;
};

template<>
struct pick_bound4<8> {
	template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
	using bound_type = ::color::_internal::utility::bound::pack4_8_t< first_size, second_size, third_size, fourth_size >;
};

template<>
struct pick_bound4<16> {
	template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
	using bound_type = ::color::_internal::utility::bound::pack4_16_t< first_size, second_size, third_size, fourth_size >;
};

template<>
struct pick_bound4<32> {
	template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
	using bound_type = ::color::_internal::utility::bound::pack4_32_t< first_size, second_size, third_size, fourth_size >;
};

template<>
struct pick_bound4<64> {
	template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
	using bound_type = ::color::_internal::utility::bound::pack4_64_t< first_size, second_size, third_size, fourth_size >;
};

}
}

template
<
	unsigned first_index, unsigned first_size,
	unsigned second_index, unsigned second_size,
	unsigned third_index, unsigned third_size,
	unsigned fourth_index, unsigned fourth_size
	>
struct bound< ::color::category::rgb< ::color::category::_internal::rgba_scramble< ::color::type::pack4< first_size, second_size, third_size, fourth_size >, first_index, second_index, third_index, fourth_index > > >
	: public ::color::trait::_internal::rgb::pick_bound4< first_size + second_size + third_size + fourth_size >:: template bound_type< first_size, second_size, third_size, fourth_size > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_float >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< >
struct container< ::color::category::rgb_double >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< >
struct container< ::color::category::rgb_ldouble >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< >
struct container< ::color::category::rgb_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< >
struct container< ::color::category::rgb_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< >
struct container< ::color::category::rgb_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {
namespace trait {

template< typename value_name, unsigned first_position, unsigned second_position, unsigned third_position >
struct container< ::color::category::rgb< ::color::category::_internal::rgb_scramble< value_name, first_position, second_position, third_position > > >
	: public ::color::_internal::utility::container::array< value_name, 3 > {
};

}
}
namespace color {
namespace trait {

template< typename value_name, unsigned first_position, unsigned second_position, unsigned third_position, unsigned fourth_position >
struct container< ::color::category::rgb< ::color::category::_internal::rgba_scramble< value_name, first_position, second_position, third_position,fourth_position > > >
	: public ::color::_internal::utility::container::array< value_name, 4 > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template
<
	typename container_name,
	typename component_name,
	typename index_name
	,unsigned first_size, unsigned second_size, unsigned third_size
	>
struct pack3 {
public:
	typedef container_name instance_type;
	typedef component_name value_type;
	typedef index_name index_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type & return_original_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;

	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitP< value_type > component_trait_type;

	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	enum { size_entity = 3 };
	enum {
		first_position = 0,
		second_position = first_size,
		third_position = first_size + second_size
	};

	enum {
		first_mask = (1 << first_size)-1 ,
		second_mask = (1 << second_size)-1 ,
		third_mask = (1 << third_size)-1
	};

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		switch(index) {
		default:
		case(0):
			return ((container >> (first_position)) & first_mask);
		case(1):
			return ((container >> (second_position)) & second_mask);
		case(2):
			return ((container >> (third_position)) & third_mask);
		}
		return 0;
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		switch(index) {
		case(0):
			return ((container >> (first_position)) & first_mask);
		case(1):
			return ((container >> (second_position)) & second_mask);
		case(2):
			return ((container >> (third_position)) & third_mask);
		}
		return 0;
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		switch(index) {
		default:
		case(0) :
			container = (container & ~(first_mask << (first_position))) | (((instance_type)value) << (first_position));
			break;
		case(1) :
			container = (container & ~(second_mask << (second_position))) | (((instance_type)value) << (second_position));
			break;
		case(2) :
			container = (container & ~(third_mask << (third_position))) | (((instance_type)value) << (third_position));
			break;
		}
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		switch(index) {
		case(0) :
			container = (container & ~(first_mask << (first_position))) | (((instance_type)value) << (first_position));
			break;
		case(1) :
			container = (container & ~(second_mask << (second_position))) | (((instance_type)value) << (second_position));
			break;
		case(2) :
			container = (container & ~(third_mask << (third_position))) | (((instance_type)value) << (third_position));
			break;
		}
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = size_entity;
		return local_length;
	}
};

template< typename container_name, typename component_name, unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_N_N_t = ::color::_internal::utility::container::pack3< container_name, component_name, unsigned, first_size, second_size, third_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_8_8_t = ::color::_internal::utility::container::pack3_N_N_t< std::uint8_t, std::uint8_t, first_size, second_size, third_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_16_8_t = ::color::_internal::utility::container::pack3_N_N_t< std::uint16_t, std::uint8_t, first_size, second_size, third_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_32_16_t = ::color::_internal::utility::container::pack3_N_N_t< std::uint32_t, std::uint16_t, first_size, second_size, third_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_64_16_t = ::color::_internal::utility::container::pack3_N_N_t< std::uint64_t, std::uint16_t, first_size, second_size, third_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size >
using pack3_64_32_t = ::color::_internal::utility::container::pack3_N_N_t< std::uint64_t, std::uint32_t, first_size, second_size, third_size >;

using split233_t = ::color::_internal::utility::container::pack3_8_8_t< 2, 3, 3 >;
using split323_t = ::color::_internal::utility::container::pack3_8_8_t< 3, 2, 3 >;
using split332_t = ::color::_internal::utility::container::pack3_8_8_t< 3, 3, 2 >;

using split422_t = ::color::_internal::utility::container::pack3_8_8_t< 4, 2, 2 >;
using split242_t = ::color::_internal::utility::container::pack3_8_8_t< 2, 4, 2 >;
using split224_t = ::color::_internal::utility::container::pack3_8_8_t< 2, 2, 4 >;

using split655_t = ::color::_internal::utility::container::pack3_16_8_t< 6, 5, 5 >;
using split565_t = ::color::_internal::utility::container::pack3_16_8_t< 5, 6, 5 >;
using split556_t = ::color::_internal::utility::container::pack3_16_8_t< 5, 5, 6 >;

}
}
}
}

namespace color {
namespace trait {
namespace _internal {
namespace rgb {

template< unsigned size_size >
struct pick_container3 {
	typedef ::color::type::error_t container_type;
};

template<>
struct pick_container3<8> {
	template< unsigned first_size, unsigned second_size, unsigned third_size >
	using container_type = ::color::_internal::utility::container::pack3_8_8_t< first_size, second_size, third_size >;
};

template<>
struct pick_container3<16> {
	template< unsigned first_size, unsigned second_size, unsigned third_size >
	using container_type = ::color::_internal::utility::container::pack3_16_8_t< first_size, second_size, third_size >;
};

template<>
struct pick_container3<32> {
	template< unsigned first_size, unsigned second_size, unsigned third_size >
	using container_type = ::color::_internal::utility::container::pack3_32_16_t< first_size, second_size, third_size >;
};

template<>
struct pick_container3<64> {
	template< unsigned first_size, unsigned second_size, unsigned third_size >
	using container_type = ::color::_internal::utility::container::pack3_64_32_t< first_size, second_size, third_size >;
};

}
}

template
<
	unsigned first_index, unsigned first_size,
	unsigned second_index, unsigned second_size,
	unsigned third_index, unsigned third_size
	>
struct container< ::color::category::rgb< ::color::category::_internal::rgb_scramble< ::color::type::pack3< first_size, second_size, third_size >, first_index, second_index, third_index > > >
	: public ::color::trait::_internal::rgb::pick_container3< first_size + second_size + third_size >:: template container_type<first_size, second_size, third_size> {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template
<
	typename container_name,
	typename component_name,
	typename index_name
	,unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size
	>
struct pack4 {
public:
	typedef container_name instance_type;
	typedef component_name value_type;
	typedef index_name index_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type & return_original_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;

	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitP< value_type > component_trait_type;

	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	enum { size_entity = 4 };
	enum {
		first_position = 0,
		second_position = first_size,
		third_position = first_size + second_size,
		fourth_position = first_size + second_size + third_size
	};

	enum {
		first_mask = (1 << first_size)-1 ,
		second_mask = (1 << second_size)-1 ,
		third_mask = (1 << third_size)-1 ,
		fourth_mask = (1 << fourth_size)-1
	};

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		switch(index) {
		default:
		case(0):
			return ((container >> (first_position)) & first_mask);
		case(1):
			return ((container >> (second_position)) & second_mask);
		case(2):
			return ((container >> (third_position)) & third_mask);
		case(3):
			return ((container >> (fourth_position)) & fourth_mask);
		}
		return 0;
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		switch(index) {
		case(0):
			return ((container >> (first_position)) & first_mask);
		case(1):
			return ((container >> (second_position)) & second_mask);
		case(2):
			return ((container >> (third_position)) & third_mask);
		case(3):
			return ((container >> (fourth_position)) & fourth_mask);
		}
		return 0;
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		switch(index) {
		default:
		case(0) :
			container = (container & ~(first_mask << (first_position))) | (((instance_type)value) << (first_position));
			break;
		case(1) :
			container = (container & ~(second_mask << (second_position))) | (((instance_type)value) << (second_position));
			break;
		case(2) :
			container = (container & ~(third_mask << (third_position))) | (((instance_type)value) << (third_position));
			break;
		case(3) :
			container = (container & ~(fourth_mask << (fourth_position))) | (((instance_type)value) << (fourth_position));
			break;
		}
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		switch(index) {
		case(0) :
			container = (container & ~(first_mask << (first_position))) | (((instance_type)value) << (first_position));
			break;
		case(1) :
			container = (container & ~(second_mask << (second_position))) | (((instance_type)value) << (second_position));
			break;
		case(2) :
			container = (container & ~(third_mask << (third_position))) | (((instance_type)value) << (third_position));
			break;
		case(3) :
			container = (container & ~(fourth_mask << (fourth_position))) | (((instance_type)value) << (fourth_position));
			break;
		}
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = size_entity;
		return local_length;
	}
};

template< typename container_name, typename component_name, unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_N_N_t = ::color::_internal::utility::container::pack4< container_name, component_name, unsigned, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_8_8_t = ::color::_internal::utility::container::pack4_N_N_t< std::uint8_t, std::uint8_t, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_16_8_t = ::color::_internal::utility::container::pack4_N_N_t< std::uint16_t, std::uint8_t, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_32_8_t = ::color::_internal::utility::container::pack4_N_N_t< std::uint32_t, std::uint8_t, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_32_16_t = ::color::_internal::utility::container::pack4_N_N_t< std::uint32_t, std::uint16_t, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_64_16_t = ::color::_internal::utility::container::pack4_N_N_t< std::uint64_t, std::uint16_t, first_size, second_size, third_size, fourth_size >;

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
using pack4_64_32_t = ::color::_internal::utility::container::pack4_N_N_t< std::uint64_t, std::uint32_t, first_size, second_size, third_size, fourth_size >;

using split2222_t = ::color::_internal::utility::container::pack4_8_8_t< 2, 2, 2, 2 >;
using split4444_t = ::color::_internal::utility::container::pack4_16_8_t< 4, 4, 4, 4 >;

using split1555_t = ::color::_internal::utility::container::pack4_16_8_t< 1, 5, 5, 5 >;
using split5551_t = ::color::_internal::utility::container::pack4_16_8_t< 5, 5, 5, 1 >;

using split8888_t = ::color::_internal::utility::container::pack4_32_8_t< 8, 8, 8, 8 >;

using split2AAA_t = ::color::_internal::utility::container::pack4_32_16_t< 2, 10, 10, 10 >;
using splitAAA2_t = ::color::_internal::utility::container::pack4_32_16_t< 10, 10, 10, 2 >;

using splitGGGG_t = ::color::_internal::utility::container::pack4_64_16_t< 16, 16, 16, 16 >;

}
}
}
}

namespace color {
namespace trait {

namespace _internal {
namespace rgb {

template< unsigned size_size >
struct pick_container4 {
	typedef ::color::type::error_t container_type;
};

template<>
struct pick_container4<8> {
	template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
	using container_type = ::color::_internal::utility::container::pack4_8_8_t< first_size, second_size, third_size, fourth_size >;
};

template<>
struct pick_container4<16> {
	template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
	using container_type = ::color::_internal::utility::container::pack4_16_8_t< first_size, second_size, third_size, fourth_size >;
};

template<>
struct pick_container4<32> {
	template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
	using container_type = ::color::_internal::utility::container::pack4_32_16_t< first_size, second_size, third_size, fourth_size >;
};

template<>
struct pick_container4<64> {
	template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
	using container_type = ::color::_internal::utility::container::pack4_64_32_t< first_size, second_size, third_size, fourth_size >;
};

}
}

template
<
	unsigned first_index, unsigned first_size,
	unsigned second_index, unsigned second_size,
	unsigned third_index, unsigned third_size,
	unsigned fourth_index, unsigned fourth_size
	>
struct container< ::color::category::rgb< ::color::category::_internal::rgba_scramble< ::color::type::pack4< first_size, second_size, third_size, fourth_size >, first_index, second_index, third_index, fourth_index > > >
	: public ::color::trait::_internal::rgb::pick_container4< first_size + second_size + third_size + fourth_size >:: template container_type<first_size, second_size, third_size, fourth_size> {
};

}
}

namespace color {

namespace _internal {

template< typename type_name >
struct pick_rgb {
	typedef ::color::category::rgb_error category_type;
};

template<> struct pick_rgb< std::uint8_t > {
	typedef ::color::category::rgb_uint8 category_type;
};
template<> struct pick_rgb< std::uint16_t > {
	typedef ::color::category::rgb_uint16 category_type;
};
template<> struct pick_rgb< std::uint32_t > {
	typedef ::color::category::rgb_uint32 category_type;
};
template<> struct pick_rgb< std::uint64_t > {
	typedef ::color::category::rgb_uint64 category_type;
};
template<> struct pick_rgb< float > {
	typedef ::color::category::rgb_float category_type;
};
template<> struct pick_rgb< double > {
	typedef ::color::category::rgb_double category_type;
};
template<> struct pick_rgb< long double > {
	typedef ::color::category::rgb_ldouble category_type;
};

template< unsigned first_size, unsigned second_size, unsigned third_size >
struct pick_rgb< ::color::type::pack3< first_size, second_size, third_size > > {
	typedef ::color::category::rgb_pack< first_size, second_size, third_size > category_type;
};

template< typename type_name >
struct pick_rgba {
	typedef ::color::category::rgba_error category_type;
};

template<> struct pick_rgba< std::uint8_t > {
	typedef ::color::category::rgba_uint8 category_type;
};
template<> struct pick_rgba< std::uint16_t > {
	typedef ::color::category::rgba_uint16 category_type;
};
template<> struct pick_rgba< std::uint32_t > {
	typedef ::color::category::rgba_uint32 category_type;
};
template<> struct pick_rgba< std::uint64_t > {
	typedef ::color::category::rgba_uint64 category_type;
};
template<> struct pick_rgba< float > {
	typedef ::color::category::rgba_float category_type;
};
template<> struct pick_rgba< double > {
	typedef ::color::category::rgba_double category_type;
};
template<> struct pick_rgba< long double > {
	typedef ::color::category::rgba_ldouble category_type;
};

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
struct pick_rgba< ::color::type::pack4< first_size, second_size, third_size, fourth_size > > {
	typedef ::color::category::rgba_pack< first_size, second_size, third_size, fourth_size > category_type;
};

template< typename type_name >
struct pick_argb {
	typedef ::color::category::argb_error category_type;
};

template<> struct pick_argb< std::uint8_t > {
	typedef ::color::category::argb_uint8 category_type;
};
template<> struct pick_argb< std::uint16_t > {
	typedef ::color::category::argb_uint16 category_type;
};
template<> struct pick_argb< std::uint32_t > {
	typedef ::color::category::argb_uint32 category_type;
};
template<> struct pick_argb< std::uint64_t > {
	typedef ::color::category::argb_uint64 category_type;
};
template<> struct pick_argb< float > {
	typedef ::color::category::argb_float category_type;
};
template<> struct pick_argb< double > {
	typedef ::color::category::argb_double category_type;
};
template<> struct pick_argb< long double > {
	typedef ::color::category::argb_ldouble category_type;
};

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
struct pick_argb< ::color::type::pack4< first_size, second_size, third_size, fourth_size > > {
	typedef ::color::category::argb_pack< first_size, second_size, third_size, fourth_size > category_type;
};

template< typename type_name >
struct pick_bgr {
	typedef ::color::category::bgr_error category_type;
};

template<> struct pick_bgr< std::uint8_t > {
	typedef ::color::category::bgr_uint8 category_type;
};
template<> struct pick_bgr< std::uint16_t > {
	typedef ::color::category::bgr_uint16 category_type;
};
template<> struct pick_bgr< std::uint32_t > {
	typedef ::color::category::bgr_uint32 category_type;
};
template<> struct pick_bgr< std::uint64_t > {
	typedef ::color::category::bgr_uint64 category_type;
};
template<> struct pick_bgr< float > {
	typedef ::color::category::bgr_float category_type;
};
template<> struct pick_bgr< double > {
	typedef ::color::category::bgr_double category_type;
};
template<> struct pick_bgr< long double > {
	typedef ::color::category::bgr_ldouble category_type;
};

template< unsigned first_size, unsigned second_size, unsigned third_size >
struct pick_bgr< ::color::type::pack3< first_size, second_size, third_size > > {
	typedef ::color::category::bgr_pack< first_size, second_size, third_size > category_type;
};

template< typename type_name >
struct pick_bgra {
	typedef ::color::category::bgra_error category_type;
};

template<> struct pick_bgra< std::uint8_t > {
	typedef ::color::category::bgra_uint8 category_type;
};
template<> struct pick_bgra< std::uint16_t > {
	typedef ::color::category::bgra_uint16 category_type;
};
template<> struct pick_bgra< std::uint32_t > {
	typedef ::color::category::bgra_uint32 category_type;
};
template<> struct pick_bgra< std::uint64_t > {
	typedef ::color::category::bgra_uint64 category_type;
};
template<> struct pick_bgra< float > {
	typedef ::color::category::bgra_float category_type;
};
template<> struct pick_bgra< double > {
	typedef ::color::category::bgra_double category_type;
};
template<> struct pick_bgra< long double > {
	typedef ::color::category::bgra_ldouble category_type;
};

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
struct pick_bgra< ::color::type::pack4< first_size, second_size, third_size, fourth_size > > {
	typedef ::color::category::bgra_pack< first_size, second_size, third_size, fourth_size > category_type;
};

template< typename type_name >
struct pick_abgr {
	typedef ::color::category::abgr_error category_type;
};

template<> struct pick_abgr< std::uint8_t > {
	typedef ::color::category::abgr_uint8 category_type;
};
template<> struct pick_abgr< std::uint16_t > {
	typedef ::color::category::abgr_uint16 category_type;
};
template<> struct pick_abgr< std::uint32_t > {
	typedef ::color::category::abgr_uint32 category_type;
};
template<> struct pick_abgr< std::uint64_t > {
	typedef ::color::category::abgr_uint64 category_type;
};
template<> struct pick_abgr< float > {
	typedef ::color::category::abgr_float category_type;
};
template<> struct pick_abgr< double > {
	typedef ::color::category::abgr_double category_type;
};
template<> struct pick_abgr< long double > {
	typedef ::color::category::abgr_ldouble category_type;
};

template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
struct pick_abgr< ::color::type::pack4< first_size, second_size, third_size, fourth_size > > {
	typedef ::color::category::abgr_pack< first_size, second_size, third_size, fourth_size > category_type;
};

}

template< typename type_name >
using rgb = ::color::model< typename ::color::_internal::pick_rgb< type_name >::category_type >;

template< typename type_name >
using rgba = ::color::model< typename ::color::_internal::pick_rgba< type_name >::category_type >;

template< typename type_name >
using argb = ::color::model< typename ::color::_internal::pick_argb< type_name >::category_type >;

template< typename type_name >
using bgr = ::color::model< typename ::color::_internal::pick_bgr< type_name >::category_type >;

template< typename type_name >
using bgra = ::color::model< typename ::color::_internal::pick_bgra< type_name >::category_type >;

template< typename type_name >
using abgr = ::color::model< typename ::color::_internal::pick_abgr< type_name >::category_type >;

}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::rgb< tag_name> >::component_const_type
red(::color::model< ::color::category::rgb<tag_name> > const& color_parameter) {
	typedef ::color::category::rgb< tag_name> category_type;
	enum { red_p = ::color::place::_internal::red<category_type>::position_enum };
	return color_parameter.template get<red_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::rgb< tag_name> >::component_const_type
green(::color::model< ::color::category::rgb< tag_name> > const& color_parameter) {
	typedef ::color::category::rgb< tag_name> category_type;
	enum { green_p = ::color::place::_internal::green<category_type>::position_enum };
	return color_parameter.template get<green_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::rgb< tag_name > >::component_const_type
blue(::color::model< ::color::category::rgb< tag_name > > const& color_parameter) {
	typedef ::color::category::rgb< tag_name > category_type;
	enum { blue_p = ::color::place::_internal::blue<category_type>::position_enum };
	return color_parameter.template get<blue_p>();
}

}
}

namespace color {
namespace get {

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
inline
typename ::color::trait::component
<
::color::category::rgb
<
::color::category::_internal::rgba_scramble < value_name, red_position, green_position, blue_position, alpha_position >
>
>::return_image_type
alpha(::color::model< ::color::category::rgb< ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > > > const& color_parameter) {
	typedef ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > tag_type;
	typedef ::color::category::rgb< tag_type > category_type;
	enum { alpha_enum = ::color::place::_internal::alpha< category_type >::position_enum };
	return color_parameter.template get< alpha_position >();
}
}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::rgb_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::rgb_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::rgb_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::rgb_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::rgb_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::rgb_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::rgb_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct luma< ::color::category::yiq< tag_name > > {
public:
	typedef ::color::category::yiq< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct inphase< ::color::category::yiq< tag_name > > {
public:
	typedef ::color::category::yiq< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct quadrature< ::color::category::yiq< tag_name > > {
public:
	typedef ::color::category::yiq< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< typename ::color::akin::yiq< ::color::category::rgb<tag_name> >::akin_type >::component_const_type
inphase(::color::model< ::color::category::rgb<tag_name> > const& color_parameter) {
	typedef ::color::category::rgb<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::yiq<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::yiq< akin_type > yiq_const_type;
	enum {
		inphase_p = ::color::place::_internal::inphase<akin_type>::position_enum
	};
	enum {
		red_p = ::color::place::_internal::red<category_type>::position_enum
		,green_p = ::color::place::_internal::green<category_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_type>::position_enum
	};
	scalar_type value =
		+ yiq_const_type::b21() * normalize_type::template process<red_p >(color_parameter.template get<red_p >())
	+ yiq_const_type::b22() * normalize_type::template process<green_p >(color_parameter.template get<green_p >())
	+ yiq_const_type::b23() * normalize_type::template process<blue_p >(color_parameter.template get<blue_p >())
	;
	value = value / yiq_const_type::i_range() + scalar_type(0.5);
	return diverse_type::template process<inphase_p>(value);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< typename ::color::akin::yiq< ::color::category::rgb<tag_name> >::akin_type >::component_const_type
quadrature(::color::model< ::color::category::rgb<tag_name> > const& color_parameter) {
	typedef ::color::category::rgb<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::yiq<category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::yiq< akin_type > yiq_const_type;
	enum {
		red_p = ::color::place::_internal::red<category_type>::position_enum
		,green_p = ::color::place::_internal::green<category_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_type>::position_enum
	};
	scalar_type value =
		+ yiq_const_type::b31() * normalize_type::template process<red_p >(color_parameter.template get<red_p >())
	+ yiq_const_type::b32() * normalize_type::template process<green_p >(color_parameter.template get<green_p >())
	+ yiq_const_type::b33() * normalize_type::template process<blue_p >(color_parameter.template get<blue_p >())
	;
	value = value / yiq_const_type::q_range() + scalar_type(0.5);
	return diverse_type::template process<2>(value);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::rgb<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::rgb<tag_name> > const& color_parameter) {
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	enum {
		red_p = ::color::place::_internal::red<category_type>::position_enum
		, green_p = ::color::place::_internal::green<category_type>::position_enum
		, blue_p = ::color::place::_internal::blue<category_type>::position_enum
	};
	scalar_type value =
		gray_const_type::Rc() * normalize_type::template process<red_p >(color_parameter.template get<red_p >())
	+ gray_const_type::Gc() * normalize_type::template process<green_p >(color_parameter.template get<green_p >())
	+ gray_const_type::Bc() * normalize_type::template process<blue_p >(color_parameter.template get<blue_p >())
	;
	return diverse_type::template process<0>(value);
}

}
}

namespace color {
namespace get {

namespace _internal {

template< typename tag_name >
inline
typename ::color::model< ::color::category::rgb< tag_name> >::component_const_type
hue
(
	::color::model< ::color::category::rgb< tag_name> > const& color_parameter
	,::color::constant::hue::_internal::algorithm< ::color::constant::hue::hexagon_entity > const& algorithm_param
) {
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type> scalar_trait_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::_internal::diverse< category_type > diverse_type;
	typedef ::color::trait::container<category_type> container_trait_type;
	enum {
		red_p = ::color::place::_internal::red<category_type>::position_enum
		,green_p = ::color::place::_internal::green<category_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_type>::position_enum
	};
	scalar_type r = normalize_type::template process<red_p >(color_parameter.template get<red_p>());
	scalar_type g = normalize_type::template process<green_p>(color_parameter.template get<green_p>());
	scalar_type b = normalize_type::template process<blue_p >(color_parameter.template get<blue_p>());
	const scalar_type hi = std::max<scalar_type>({ r, g, b });
	const scalar_type lo = std::min<scalar_type>({ r, g, b });
	scalar_type delta = hi - lo;
	scalar_type h = 0;
	if(false == scalar_trait_type::is_small(delta)) {
		if(hi == r) {
			h = (scalar_type(60)/scalar_type(360)) * (g - b) / delta + (g < b ? scalar_type(1) : scalar_type(0));
		}
		if(hi == g) {
			h = (scalar_type(60)/scalar_type(360)) * (b - r) / delta + (scalar_type(120)/scalar_type(360));
		}
		if(hi == b) {
			h = (scalar_type(60)/scalar_type(360)) * (r - g) / delta + (scalar_type(240)/scalar_type(360));
		}
	}
	return diverse_type::template process< red_p >(h);
}

template< typename tag_name >
inline
typename ::color::model< ::color::category::rgb< tag_name> >::component_const_type
hue
(
	::color::model< ::color::category::rgb< tag_name> > const& color_parameter
	,::color::constant::hue::_internal::algorithm< ::color::constant::hue::polar_atan2_entity > const& algorithm_param
) {
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::_internal::diverse< category_type > diverse_type;
	typedef ::color::constant::generic< category_type > generic_constant_type;
	enum {
		red_p = ::color::place::_internal::red<category_type>::position_enum
		,green_p = ::color::place::_internal::green<category_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_type>::position_enum
	};
	scalar_type r = normalize_type::template process<red_p >(color_parameter.template get<red_p>());
	scalar_type g = normalize_type::template process<green_p>(color_parameter.template get<green_p>());
	scalar_type b = normalize_type::template process<blue_p >(color_parameter.template get<blue_p>());
	scalar_type h = 0;
	scalar_type c1 = r - g* scalar_type(0.5) - b * scalar_type(0.5);
	scalar_type c2 = (g - b) * generic_constant_type::sqrt_3() * scalar_type(0.5);
	scalar_type thetaX = atan2(c2, c1);
	if(thetaX < 0) {
		thetaX += generic_constant_type::two_pi();
	}
	h = thetaX;
	h /= generic_constant_type::two_pi();
	return diverse_type::template process< red_p >(h);
}

template< typename tag_name >
inline
typename ::color::model< ::color::category::rgb< tag_name> >::component_const_type
hue
(
	::color::model< ::color::category::rgb< tag_name> > const& color_parameter
	,::color::constant::hue::_internal::algorithm< ::color::constant::hue::polar_acos_entity > const& algorithm_param
) {
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::_internal::diverse< category_type > diverse_type;
	typedef ::color::constant::generic< category_type > generic_constant_type;
	enum {
		red_p = ::color::place::_internal::red<category_type>::position_enum
		,green_p = ::color::place::_internal::green<category_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_type>::position_enum
	};
	scalar_type r = normalize_type::template process<red_p >(color_parameter.template get<red_p>());
	scalar_type g = normalize_type::template process<green_p>(color_parameter.template get<green_p>());
	scalar_type b = normalize_type::template process<blue_p >(color_parameter.template get<blue_p>());
	scalar_type h = 0;
	scalar_type alpha = ((r-g) + (r- b)) * scalar_type(0.5);
	scalar_type beta = (r-g)*(r-g) + (r-b)*(g-b) ;
	beta = sqrt(beta);
	scalar_type thetaA = acos(alpha / beta);
	if(b > g) {
		thetaA = generic_constant_type::two_pi() - thetaA;
	}
	h = thetaA;
	h /= generic_constant_type::two_pi();
	return diverse_type::template process< red_p >(h);
}

}

template
<
	enum ::color::constant::hue::formula_enum hue_number = ::color::constant::hue::hexagon_entity
,typename tag_name
>
inline
typename ::color::model< ::color::category::rgb< tag_name> >::component_const_type
hue
(
	::color::model< ::color::category::rgb< tag_name> > const& color_parameter
) {
	return ::color::get::_internal::hue< tag_name >(color_parameter, ::color::constant::hue::_internal::algorithm< hue_number >{});
}

}
}

namespace color {
namespace set {
template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::rgb<tag_name> > & color_parameter,
	typename ::color::model< ::color::category::rgb<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::rgb<tag_name> category_type;
	enum { red_p = ::color::place::_internal::red<category_type>::position_enum };
	color_parameter.template set<red_p>(component_parameter);
}

}
}

namespace color {
namespace set {
template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::rgb<tag_name> > & color_parameter,
	typename ::color::model< ::color::category::rgb<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::rgb<tag_name> category_type;
	enum { green_p = ::color::place::_internal::green<category_type>::position_enum };
	color_parameter.template set<green_p>(component_parameter);
}

}
}

namespace color {
namespace set {
template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::rgb<tag_name> > & color_parameter,
	typename ::color::model< ::color::category::rgb<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::rgb<tag_name> category_type;
	enum { blue_p = ::color::place::_internal::blue<category_type>::position_enum };
	color_parameter.template set<blue_p>(component_parameter);
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::rgb<tag_name> > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray<::color::category::rgb<tag_name> >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::rgb<tag_name> category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray<category_type >::akin_type akin_type;
	typedef ::color::_internal::normalize< category_type > normalize_rgb_type;
	typedef ::color::_internal::normalize< akin_type > normalize_akin_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	enum {
		red_p = ::color::place::_internal::red<category_type>::position_enum
		, green_p = ::color::place::_internal::green<category_type>::position_enum
		, blue_p = ::color::place::_internal::blue<category_type>::position_enum
	};
	scalar_type value =
		gray_const_type::Rc() * normalize_rgb_type::template process<red_p >(color_parameter.template get<red_p >())
	+ gray_const_type::Gc() * normalize_rgb_type::template process<green_p>(color_parameter.template get<green_p>())
	+ gray_const_type::Bc() * normalize_rgb_type::template process<blue_p >(color_parameter.template get<blue_p >());
	value = normalize_akin_type::template process<0>(component_parameter) / value;
	::color::operation::scale(color_parameter, value);
}

}
}

namespace color {
namespace set {
template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
inline
void
alpha
(
	::color::model< ::color::category::rgb< ::color::category::_internal::rgba_scramble < value_name, red_position, green_position, blue_position, alpha_position > > > & color_parameter
	,typename ::color::model< ::color::category::rgb< ::color::category::_internal::rgba_scramble < value_name, red_position, green_position, blue_position, alpha_position > > >::component_input_const_type component_parameter
) {
	typedef ::color::category::_internal::rgba_scramble < value_name, red_position, green_position, blue_position, alpha_position > tag_type;
	typedef ::color::category::rgb<tag_type> category_type;
	enum { alpha_p = ::color::place::_internal::alpha<category_type>::position_enum };
	color_parameter.template set<alpha_p>(component_parameter);
}

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename gray_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::gray<gray_tag_name>
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::gray<gray_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
			,green_p = ::color::place::_internal::green<category_left_type>::position_enum
			,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		enum {
			gray_p = 0
		};
		auto const value = container_right_trait_type::template get<gray_p>(right);
		container_left_trait_type::template set<red_p >(left, reformat_type::template process<red_p ,gray_p>(value));
		container_left_trait_type::template set<green_p>(left, reformat_type::template process<green_p,gray_p>(value));
		container_left_trait_type::template set<blue_p >(left, reformat_type::template process<blue_p ,gray_p>(value));
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, double > reformat_type;
	typedef ::color::operation::_internal::invert< category_right_type > invert_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<red_p >(left, reformat_type::template process<red_p , cyan_p>(invert_type::template component< cyan_p>(container_right_trait_type::template get< cyan_p>(right))));
		container_left_trait_type::template set<green_p>(left, reformat_type::template process<green_p, magenta_p>(invert_type::template component<magenta_p>(container_right_trait_type::template get<magenta_p>(right))));
		container_left_trait_type::template set<blue_p >(left, reformat_type::template process<blue_p , yellow_p>(invert_type::template component< yellow_p>(container_right_trait_type::template get< yellow_p>(right))));
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::cmyk<cmyk_tag_name>
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::cmyk<cmyk_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
			,green_p = ::color::place::_internal::green<category_left_type>::position_enum
			,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		enum {
			cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
			,yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
			,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
			,key_p = ::color::place::_internal::key<category_right_type>::position_enum
		};
		scalar_type c = normalize_type::template process< cyan_p>(container_right_trait_type::template get< cyan_p>(right));
		scalar_type m = normalize_type::template process< magenta_p>(container_right_trait_type::template get< magenta_p>(right));
		scalar_type y = normalize_type::template process< yellow_p>(container_right_trait_type::template get< yellow_p>(right));
		scalar_type k = normalize_type::template process< key_p>(container_right_trait_type::template get< key_p>(right));
		scalar_type r = (1-c) * (1-k);
		scalar_type g = (1-m) * (1-k);
		scalar_type b = (1-y) * (1-k);
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::gray_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::gray_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::gray_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::gray_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::gray_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::gray_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::gray_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::cmy_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::cmy_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::cmy_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::cmy_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::cmy_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::cmy_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::cmy_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::cmyk_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::cmyk_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::cmyk_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::cmyk_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::cmyk_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::cmyk_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::cmyk_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct hsl< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::hsv_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::hsv_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::hsv_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::hsv_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::hsv_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::hsv_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::hsv_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::hsi_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::hsi_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::hsi_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::hsi_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::hsi_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::hsi_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::hsi_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::rgb_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::rgb_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::rgb_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::rgb_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::rgb_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::rgb_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::rgb_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::yiq_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::yiq_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::yiq_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::yiq_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::yiq_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::yiq_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::yiq_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct hsl< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsl< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsl< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsl< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsl< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::hsl_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsl< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::hsl_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsl< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::xyz_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::xyz_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::xyz_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::xyz_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::xyz_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::xyz_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::xyz_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::hsl_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsl_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsl_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsl_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsl_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsl_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsl_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct hsl_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsl_float >
	: public ::color::_internal::utility::bound::hsl_scalar< unsigned, float > {
};

template< >
struct bound< ::color::category::hsl_double >
	: public ::color::_internal::utility::bound::hsl_scalar< unsigned, double > {
};

template< >
struct bound< ::color::category::hsl_ldouble >
	: public ::color::_internal::utility::bound::hsl_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsl_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::hsl_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::hsl_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::hsl_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsl_float >
	: public ::color::_internal::utility::component::array< float, unsigned> {
};

template< >
struct component< ::color::category::hsl_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::hsl_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsl_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::hsl_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::hsl_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::hsl_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsl_float >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< >
struct container< ::color::category::hsl_double >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< >
struct container< ::color::category::hsl_ldouble >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsl_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< >
struct container< ::color::category::hsl_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< >
struct container< ::color::category::hsl_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< >
struct container< ::color::category::hsl_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {

template< typename type_name >
using hsl = ::color::model< ::color::category::hsl< type_name > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct hue< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace check {
namespace _internal {

template<>
struct integrity< ::color::category::hsl_float> {
public:
	typedef ::color::category::hsl_float category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			return false;
		}
		if(bound_type::template maximum<hue_p>() < m.template get<hue_p>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsl_double > {
public:
	typedef ::color::category::hsl_double category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			return false;
		}
		if(bound_type::template maximum<hue_p>() < m.template get<hue_p>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsl_ldouble > {
public:
	typedef ::color::category::hsl_ldouble category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			return false;
		}
		if(bound_type::template maximum<hue_p>() < m.template get<hue_p>()) {
			return false;
		}
		return true;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct lightness< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct saturation< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace check {
namespace _internal {

template< typename category_name >
struct unique {
public:
	typedef category_name category_type;

	typedef ::color::model<category_type> model_type;

	static bool process(model_type const& m) {
		return true;
	}

};
}

template< typename category_name >
inline
bool unique(::color::model<category_name> const& m) {
	return ::color::check::_internal::unique<category_name>::process(m);
}

}
}

namespace color {
namespace check {
namespace _internal {

template< typename tag_name >
struct unique< ::color::category::hsl< tag_name> > {
public:
	typedef ::color::category::hsl<tag_name> category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		, lightness_p = ::color::place::_internal::lightness<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<saturation_p>() == bound_type::template minimum<saturation_p>()) {
			return false;
		}
		if(m.template get< lightness_p>() == bound_type::template minimum< lightness_p>()) {
			return false;
		}
		if(m.template get< lightness_p>() == bound_type::template maximum< lightness_p>()) {
			return false;
		}
		return true;
	}
};

}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsl<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::hsl<tag_name> > const& color_parameter) {
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	enum { lightness_p = ::color::place::_internal::lightness<category_type>::position_enum };
	scalar_type g = normalize_type::template process<lightness_p >(color_parameter.template get<lightness_p >());
	return diverse_type::template process<0>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsl<tag_name> >::akin_type >::return_type
red(::color::model< ::color::category::hsl<tag_name> > const& color_parameter) {
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	return ::color::model< akin_type >(color_parameter).template get<red_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsl<tag_name> >::akin_type >::return_type
green(::color::model< ::color::category::hsl<tag_name> > const& color_parameter) {
	typedef ::color::category::hsl<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	return ::color::model< akin_type >(color_parameter).template get<green_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsl<tag_name> >::akin_type >::return_type
blue(::color::model< ::color::category::hsl<tag_name> > const& color_parameter) {
	typedef ::color::category::hsl<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	return ::color::model< akin_type >(color_parameter).template get<blue_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::hsl< tag_name> >::component_const_type
hue(::color::model< ::color::category::hsl< tag_name> > const& color_parameter) {
	typedef ::color::category::hsl< tag_name> category_type;
	enum { hue_p = ::color::place::_internal::hue<category_type>::position_enum };
	return color_parameter.template get<hue_p>();
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
hue
(
	::color::model< ::color::category::hsl<tag_name> > & color_parameter
	,typename ::color::model< ::color::category::hsl<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::hsl< tag_name > category_type;
	enum { hue_p = ::color::place::_internal::hue< category_type >::position_enum };
	color_parameter.template set<hue_p>(component_parameter);
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::hsl< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsl< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<blue_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::hsl< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsl< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::hsl< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsl< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<red_p> (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::hsl<tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsl< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef double scalar_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	enum {
		lightness_p = ::color::place::_internal::lightness<category_type>::position_enum
	};
	color_parameter.template set<lightness_p>(reformat_type::template process<lightness_p,0>(component_parameter));
}

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename gray_tag_name >
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		, lightness_p = ::color::place::_internal::lightness<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<hue_p>(left, bound_left_trait_type::template minimum<hue_p>());
		container_left_trait_type::template set<saturation_p>(left, bound_left_trait_type::template minimum<saturation_p>());
		container_left_trait_type::template set<lightness_p>(left, reformat_type::template process<lightness_p,0>(container_right_trait_type::template get<0>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar<category_left_type> scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		, lightness_p = ::color::place::_internal::lightness<category_left_type>::position_enum
	};

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = scalar_type(1) - normalize_type::template process< cyan_p>(container_right_trait_type::template get< cyan_p>(right));
		scalar_type g = scalar_type(1) - normalize_type::template process< magenta_p>(container_right_trait_type::template get< magenta_p>(right));
		scalar_type b = scalar_type(1) - normalize_type::template process< yellow_p>(container_right_trait_type::template get< yellow_p>(right));
		const scalar_type hi = std::max<scalar_type>({ r, g, b });
		const scalar_type lo = std::min<scalar_type>({ r, g, b });
		scalar_type delta = hi - lo;
		scalar_type h = 0;
		scalar_type s = 0;
		scalar_type l = (hi + lo) / scalar_type(2);
		if(false == scalar_trait_type::is_small(delta)) {
			s = delta / (1 - fabs(2*l - 1));
			if(hi == r) {
				h = (scalar_type(60)/scalar_type(360)) * (g - b) / delta + (g < b ? scalar_type(1) : scalar_type(0));
			}
			if(hi == g) {
				h = (scalar_type(60)/scalar_type(360)) * (b - r) / delta + (scalar_type(120)/scalar_type(360));
			}
			if(hi == b) {
				h = (scalar_type(60)/scalar_type(360)) * (r - g) / delta + (scalar_type(240)/scalar_type(360));
			}
		}
		container_left_trait_type::template set< hue_p>(left, diverse_type::template process< hue_p>(h));
		container_left_trait_type::template set<saturation_p>(left, diverse_type::template process<saturation_p>(s));
		container_left_trait_type::template set< lightness_p>(left, diverse_type::template process< lightness_p>(l));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::cmyk< cmyk_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_left_type;
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmyk_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsl_category_type > hsl_model_type;
	typedef ::color::model< cmyk_category_type > cmyk_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsl_model_type(rgb_model_type(cmyk_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::hsl< tag_left_name >
	,::color::category::hsl< tag_right_name>
	> {
public:
	typedef ::color::category::hsl< tag_left_name > category_left_type;
	typedef ::color::category::hsl< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::gray_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::gray_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::gray_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::gray_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::gray_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::gray_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::gray_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::cmy_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::cmy_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::cmy_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::cmy_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::cmy_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::cmy_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::cmy_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::cmyk_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::cmyk_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::cmyk_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::cmyk_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::cmyk_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::cmyk_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::cmyk_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::hsl_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::hsl_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::hsl_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::hsl_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::hsl_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::hsl_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::hsl_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct hsv< ::color::category::hsv< tag_name > > {
public:
	typedef ::color::category::hsv< tag_name > akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::hsi_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::hsi_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::hsi_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::hsi_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::hsi_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::hsi_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::hsi_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::rgb_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::rgb_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::rgb_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::rgb_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::rgb_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::rgb_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::rgb_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::yiq_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::yiq_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::yiq_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::yiq_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::yiq_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::yiq_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::yiq_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct hsv< ::color::category::yuv_uint8 <reference_number> > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsv< ::color::category::yuv_uint16 <reference_number> > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsv< ::color::category::yuv_uint32 <reference_number> > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsv< ::color::category::yuv_uint64 <reference_number> > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsv< ::color::category::yuv_float <reference_number> > {
	typedef ::color::category::hsv_float akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsv< ::color::category::yuv_double <reference_number> > {
	typedef ::color::category::hsv_double akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsv< ::color::category::yuv_ldouble<reference_number> > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::YCgCo_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::YCgCo_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::YCgCo_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::YCgCo_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::YCgCo_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::YCgCo_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::YCgCo_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::YDbDr_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::YDbDr_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::YDbDr_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::YDbDr_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::YDbDr_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::YDbDr_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::YDbDr_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct hsv< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsv< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsv< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsv< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsv< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::hsv_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsv< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::hsv_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsv< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::xyz_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::xyz_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::xyz_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::xyz_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::xyz_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::xyz_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::xyz_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::hsv_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsv_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsv_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsv_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsv_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsv_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsv_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct hsv_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsv_float >
	: public ::color::_internal::utility::bound::hsv_scalar< unsigned, float > {
};

template< >
struct bound< ::color::category::hsv_double >
	: public ::color::_internal::utility::bound::hsv_scalar< unsigned, double > {
};

template< >
struct bound< ::color::category::hsv_ldouble >
	: public ::color::_internal::utility::bound::hsv_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsv_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::hsv_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::hsv_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::hsv_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsv_float >
	: public ::color::_internal::utility::component::array< float, unsigned> {
};

template< >
struct component< ::color::category::hsv_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::hsv_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsv_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::hsv_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::hsv_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::hsv_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsv_float >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< >
struct container< ::color::category::hsv_double >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< >
struct container< ::color::category::hsv_ldouble >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsv_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< >
struct container< ::color::category::hsv_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< >
struct container< ::color::category::hsv_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< >
struct container< ::color::category::hsv_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {

template< typename type_name >
using hsv = ::color::model< ::color::category::hsv< type_name > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct hue< ::color::category::hsv< tag_name > > {
public:
	typedef ::color::category::hsv< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace check {
namespace _internal {

template<>
struct integrity< ::color::category::hsv_float> {
public:
	typedef ::color::category::hsv_float category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			return false;
		}
		if(bound_type::template maximum<hue_p>() < m.template get<hue_p>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsv_double > {
public:
	typedef ::color::category::hsv_double category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			return false;
		}
		if(bound_type::template maximum<hue_p>() < m.template get<hue_p>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsv_ldouble > {
public:
	typedef ::color::category::hsv_ldouble category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			return false;
		}
		if(bound_type::template maximum<hue_p>() < m.template get<hue_p>()) {
			return false;
		}
		return true;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct saturation< ::color::category::hsv< tag_name > > {
public:
	typedef ::color::category::hsv< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct value< ::color::category::hsv< tag_name > > {
public:
	typedef ::color::category::hsv< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace check {
namespace _internal {

template< typename tag_name >
struct unique< ::color::category::hsv< tag_name > > {
public:
	typedef ::color::category::hsv< tag_name > category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		,value_p = ::color::place::_internal::value<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<saturation_p>() == bound_type::template minimum<saturation_p>()) {
			return false;
		}
		if(m.template get<value_p>() == bound_type::template minimum<value_p>()) {
			return false;
		}
		return true;
	}
};

}
}
}

namespace color {
namespace fix {
namespace _internal {

template< typename tag_name >
struct unique< ::color::category::hsv< tag_name > > {
public:
	typedef ::color::category::hsv< tag_name > category_type;

	typedef typename ::color::model<category_type> model_type;
	typedef typename ::color::trait::bound<category_type> bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		,value_p = ::color::place::_internal::value<category_type>::position_enum
	};

	static void process(model_type &result) {
		if(result.template get<value_p>() == bound_type::template minimum<value_p>()) {
			result.template set<hue_p>(bound_type::template minimum<hue_p>());
			result.template set<saturation_p>(bound_type::template minimum<saturation_p>());
			return;
		}
		if(result.template get<saturation_p>() == bound_type::template minimum<saturation_p>()) {
			result.template set<hue_p>(bound_type::template minimum<hue_p>());
			return;
		}
	}

	static void process(model_type &result, model_type const& right) {
		if(result.template get<value_p>() == bound_type::template minimum<value_p>()) {
			result.template set<hue_p>(bound_type::template minimum<hue_p>());
			result.template set<saturation_p>(bound_type::template minimum<saturation_p>());
			return;
		}
		if(result.template get<saturation_p>() == bound_type::template minimum<saturation_p>()) {
			result.template set<hue_p>(bound_type::template minimum<hue_p>());
			return;
		}
		result = right;
		return;
	}

};

}
}
}

namespace color {
namespace fix {
namespace _internal {
namespace _privateHSV {

template< typename category_name >
struct integrity {
public:
	typedef category_name category_type;

	typedef typename ::color::model<category_type> model_type;
	typedef typename ::color::trait::bound<category_type> bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static void process(model_type &result) {
		if(result.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			result.template set<hue_p>(bound_type::template minimum<hue_p>());
			return;
		}
		if(bound_type::template maximum<hue_p>() < result.template get<hue_p>()) {
			result.template set<hue_p>(bound_type::template maximum<hue_p>());
			return;
		}
	}

	static void process(model_type &result, model_type const& right) {
		result = right;
		if(result.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			result.template set<hue_p>(bound_type::template minimum<hue_p>());
			return;
		}
		if(bound_type::template maximum<hue_p>() < result.template get<hue_p>()) {
			result.template set<hue_p>(bound_type::template maximum<hue_p>());
			return;
		}
	}

};

}

template<> struct integrity< ::color::category::hsv_float > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_float > { };
template<> struct integrity< ::color::category::hsv_double > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_double > { };
template<> struct integrity< ::color::category::hsv_ldouble > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_ldouble> { };

}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsv<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::hsv<tag_name> > const& color_parameter) {
	typedef ::color::category::hsv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::gray<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	enum { value_p = ::color::place::_internal::value<category_type>::position_enum };
	scalar_type g = normalize_type::template process<value_p >(color_parameter.template get<value_p >());
	return diverse_type::template process<0>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsv<tag_name> >::akin_type >::return_type
red(::color::model< ::color::category::hsv<tag_name> > const& color_parameter) {
	typedef ::color::category::hsv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	enum {
		red_p = ::color::place::_internal::red<akin_type>::position_enum
		,green_p = ::color::place::_internal::green<akin_type>::position_enum
		,blue_p = ::color::place::_internal::blue<akin_type>::position_enum
	};
	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		,value_p = ::color::place::_internal::value<category_type>::position_enum
	};
	scalar_type h = normalize_type::template process<hue_p >(color_parameter.template get<hue_p >());
	scalar_type s = normalize_type::template process<saturation_p>(color_parameter.template get<saturation_p>());
	scalar_type v = normalize_type::template process<value_p >(color_parameter.template get<value_p >());
	int region = int(6 * h);
	scalar_type f = h * 6 - region ;
	scalar_type p = v * (1 - s);
	scalar_type q = v * (1 - f * s);
	scalar_type t = v * (1 - (1 - f) * s);
	scalar_type r;
	switch(region % 6) {
	case 0:
		r = v;
		break;
	case 1:
		r = q;
		break;
	case 2:
		r = p;
		break;
	case 3:
		r = p;
		break;
	case 4:
		r = t;
		break;
	case 5:
		r = v;
		break;
	}
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsv<tag_name> >::akin_type >::return_type
green(::color::model< ::color::category::hsv<tag_name> > const& color_parameter) {
	typedef ::color::category::hsv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	enum {
		red_p = ::color::place::_internal::red<akin_type>::position_enum
		,green_p = ::color::place::_internal::green<akin_type>::position_enum
		,blue_p = ::color::place::_internal::blue<akin_type>::position_enum
	};
	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		,value_p = ::color::place::_internal::value<category_type>::position_enum
	};
	scalar_type h = normalize_type::template process<hue_p >(color_parameter.template get<hue_p >());
	scalar_type s = normalize_type::template process<saturation_p>(color_parameter.template get<saturation_p>());
	scalar_type v = normalize_type::template process<value_p >(color_parameter.template get<value_p >());
	int region = int(6 * h);
	scalar_type f = h * 6 - region ;
	scalar_type p = v * (1 - s);
	scalar_type q = v * (1 - f * s);
	scalar_type t = v * (1 - (1 - f) * s);
	scalar_type g;
	switch(region % 6) {
	case 0:
		g = t;
		break;
	case 1:
		g = v;
		break;
	case 2:
		g = v;
		break;
	case 3:
		g = q;
		break;
	case 4:
		g = p;
		break;
	case 5:
		g = p;
		break;
	}
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsv<tag_name> >::akin_type >::return_type
blue(::color::model< ::color::category::hsv<tag_name> > const& color_parameter) {
	typedef ::color::category::hsv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	enum {
		red_p = ::color::place::_internal::red<akin_type>::position_enum
		,green_p = ::color::place::_internal::green<akin_type>::position_enum
		,blue_p = ::color::place::_internal::blue<akin_type>::position_enum
	};
	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		,value_p = ::color::place::_internal::value<category_type>::position_enum
	};
	scalar_type h = normalize_type::template process<hue_p >(color_parameter.template get<hue_p >());
	scalar_type s = normalize_type::template process<saturation_p>(color_parameter.template get<saturation_p>());
	scalar_type v = normalize_type::template process<value_p >(color_parameter.template get<value_p >());
	int region = int(6 * h);
	scalar_type f = h * 6 - region ;
	scalar_type p = v * (1 - s);
	scalar_type q = v * (1 - f * s);
	scalar_type t = v * (1 - (1 - f) * s);
	scalar_type b;
	switch(region % 6) {
	case 0:
		b = p;
		break;
	case 1:
		b = p;
		break;
	case 2:
		b = t;
		break;
	case 3:
		b = v;
		break;
	case 4:
		b = v;
		break;
	case 5:
		b = q;
		break;
	}
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::hsv< tag_name> >::component_const_type
hue(::color::model< ::color::category::hsv< tag_name> > const& color_parameter) {
	typedef ::color::category::hsv< tag_name> category_type;
	enum { hue_p = ::color::place::_internal::hue<category_type>::position_enum };
	return color_parameter.template get<hue_p>();
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
hue
(
	::color::model< ::color::category::hsv< tag_name > > & color_parameter
	,typename ::color::model< ::color::category::hsv< tag_name > >::component_input_const_type component_parameter
) {
	typedef ::color::category::hsv< tag_name > category_type;
	enum { hue_p = ::color::place::_internal::hue< category_type >::position_enum };
	color_parameter.template set<hue_p>(component_parameter);
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::hsv< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsv< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsv< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<blue_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::hsv< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsv< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsv< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::hsv< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsv< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsv< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<red_p> (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::hsv< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsv< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsv< tag_name > category_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef double scalar_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	enum {
		value_p = ::color::place::_internal::value<category_type>::position_enum
	};
	color_parameter.template set<value_p>(reformat_type::template process<value_p,0>(component_parameter));
}

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename gray_tag_name >
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		,value_p = ::color::place::_internal::value<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<hue_p>(left, bound_left_trait_type::template minimum<hue_p>());
		container_left_trait_type::template set<saturation_p>(left, bound_left_trait_type::template minimum<saturation_p>());
		container_left_trait_type::template set<value_p>(left, reformat_type::template process<value_p,0>(container_right_trait_type::template get<0>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar<category_left_type> scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_left_type >::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		,value_p = ::color::place::_internal::value<category_left_type>::position_enum
	};

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		,yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = scalar_type(1) - normalize_type::template process<cyan_p >(container_right_trait_type::template get<cyan_p >(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<magenta_p>(container_right_trait_type::template get<magenta_p >(right));
		scalar_type b = scalar_type(1) - normalize_type::template process<yellow_p >(container_right_trait_type::template get<yellow_p>(right));
		scalar_type lo = std::min<scalar_type>({r,g,b});
		scalar_type v = std::max<scalar_type>({r,g,b});
		scalar_type delta = v - lo;
		scalar_type h = 0;
		scalar_type s = 0;
		if((false == scalar_trait_type::is_small(v))
		   && (false == scalar_trait_type::is_small(delta))) {
			s = delta / v;
			if(v == r) {
				h = (scalar_type(60)/scalar_type(360)) * (g - b) / delta + (g < b ? scalar_type(1) : scalar_type(0));
			}
			if(v == g) {
				h = (scalar_type(60)/scalar_type(360)) * (b - r) / delta + (scalar_type(120)/scalar_type(360));
			}
			if(v == b) {
				h = (scalar_type(60)/scalar_type(360)) * (r - g) / delta + (scalar_type(240)/scalar_type(360));
			}
		}
		container_left_trait_type::template set<hue_p >(left, diverse_type::template process<hue_p >(h));
		container_left_trait_type::template set<saturation_p>(left, diverse_type::template process<saturation_p>(s));
		container_left_trait_type::template set<value_p >(left, diverse_type::template process<value_p >(v));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::cmyk< cmyk_tag_name >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_left_type;
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmyk_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsv_category_type > hsv_model_type;
	typedef ::color::model< cmyk_category_type > cmyk_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsv_model_type(rgb_model_type(cmyk_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::hsl< hsl_tag_name >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		hl_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,sl_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		,vl_p = ::color::place::_internal::value<category_left_type>::position_enum
	};

	enum {
		hr_p = ::color::place::_internal::hue<category_right_type>::position_enum
		,sr_p = ::color::place::_internal::saturation<category_right_type>::position_enum
		,lr_p = ::color::place::_internal::lightness<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<hr_p>(container_right_trait_type::template get<hr_p>(right));
		scalar_type ss = normalize_type::template process<sr_p>(container_right_trait_type::template get<sr_p>(right));
		scalar_type l = normalize_type::template process<lr_p>(container_right_trait_type::template get<lr_p>(right));
		scalar_type v = (2 * l + ss*(1 - fabs(2*l-1))) /2;
		scalar_type s = 2*(v - l) / v;
		container_left_trait_type::template set<hl_p>(left, diverse_type::template process<hl_p>(h));
		container_left_trait_type::template set<sl_p>(left, diverse_type::template process<sl_p>(s));
		container_left_trait_type::template set<vl_p>(left, diverse_type::template process<vl_p>(v));
	}
};

}
}
namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::hsv< tag_left_name >
	,::color::category::hsv< tag_right_name>
	> {
public:
	typedef ::color::category::hsv< tag_left_name > category_left_type;
	typedef ::color::category::hsv< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		hl_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,sl_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		,vl_p = ::color::place::_internal::value<category_left_type>::position_enum
	};

	enum {
		hr_p = ::color::place::_internal::hue<category_right_type>::position_enum
		,sr_p = ::color::place::_internal::saturation<category_right_type>::position_enum
		,vr_p = ::color::place::_internal::value<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<hl_p>(left, reformat_type::template process<hl_p,hr_p>(container_right_trait_type::template get<hr_p>(right)));
		container_left_trait_type::template set<sl_p>(left, reformat_type::template process<sl_p,sr_p>(container_right_trait_type::template get<sr_p>(right)));
		container_left_trait_type::template set<vl_p>(left, reformat_type::template process<vl_p,vr_p>(container_right_trait_type::template get<vr_p>(right)));
	}
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct hsi {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::gray_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::gray_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::gray_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::gray_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::gray_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::gray_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::gray_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::cmy_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::cmy_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::cmy_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::cmy_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::cmy_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::cmy_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::cmy_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::cmyk_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::cmyk_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::cmyk_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::cmyk_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::cmyk_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::cmyk_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::cmyk_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::hsl_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::hsl_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::hsl_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::hsl_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::hsl_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::hsl_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::hsl_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::hsv_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::hsv_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::hsv_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::hsv_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::hsv_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::hsv_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::hsv_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct hsi< ::color::category::hsi< tag_name > > {
public:
	typedef ::color::category::hsi< tag_name > akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::rgb_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::rgb_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::rgb_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::rgb_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::rgb_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::rgb_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::rgb_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::yiq_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::yiq_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::yiq_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::yiq_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::yiq_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::yiq_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::yiq_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct hsi< ::color::category::yuv_uint8 <reference_number> > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsi< ::color::category::yuv_uint16 <reference_number> > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsi< ::color::category::yuv_uint32 <reference_number> > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsi< ::color::category::yuv_uint64 <reference_number> > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsi< ::color::category::yuv_float <reference_number> > {
	typedef ::color::category::hsi_float akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsi< ::color::category::yuv_double <reference_number> > {
	typedef ::color::category::hsi_double akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct hsi< ::color::category::yuv_ldouble<reference_number> > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::YCgCo_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::YCgCo_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::YCgCo_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::YCgCo_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::YCgCo_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::YCgCo_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::YCgCo_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::YDbDr_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::YDbDr_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::YDbDr_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::YDbDr_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::YDbDr_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::YDbDr_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::YDbDr_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct hsi< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsi< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsi< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsi< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsi< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::hsi_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsi< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::hsi_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct hsi< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsi< ::color::category::xyz_uint8 > {
	typedef ::color::category::hsi_uint8 akin_type;
};
template< >struct hsi< ::color::category::xyz_uint16 > {
	typedef ::color::category::hsi_uint16 akin_type;
};
template< >struct hsi< ::color::category::xyz_uint32 > {
	typedef ::color::category::hsi_uint32 akin_type;
};
template< >struct hsi< ::color::category::xyz_uint64 > {
	typedef ::color::category::hsi_uint64 akin_type;
};
template< >struct hsi< ::color::category::xyz_float > {
	typedef ::color::category::hsi_float akin_type;
};
template< >struct hsi< ::color::category::xyz_double > {
	typedef ::color::category::hsi_double akin_type;
};
template< >struct hsi< ::color::category::xyz_ldouble > {
	typedef ::color::category::hsi_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::hsi_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsi_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsi_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsi_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsi_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsi_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::hsi_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct hsi_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsi_float >
	: public ::color::_internal::utility::bound::hsi_scalar< unsigned, float > {
};

template< >
struct bound< ::color::category::hsi_double >
	: public ::color::_internal::utility::bound::hsi_scalar< unsigned, double > {
};

template< >
struct bound< ::color::category::hsi_ldouble >
	: public ::color::_internal::utility::bound::hsi_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsi_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::hsi_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::hsi_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::hsi_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsi_float >
	: public ::color::_internal::utility::component::array< float, unsigned> {
};

template< >
struct component< ::color::category::hsi_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::hsi_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsi_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::hsi_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::hsi_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::hsi_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsi_float >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< >
struct container< ::color::category::hsi_double >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< >
struct container< ::color::category::hsi_ldouble >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsi_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< >
struct container< ::color::category::hsi_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< >
struct container< ::color::category::hsi_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

template< >
struct container< ::color::category::hsi_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

}
}

namespace color {
namespace constant {

template< typename category_name>
struct hsi {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::hsi<category_type> this_type;

	static scalar_type const two() {
		return 2;
	}
	static scalar_type const third() {
		return scalar_type(1) / scalar_type(3);
	}
	static scalar_type const sixth() {
		return scalar_type(1) / scalar_type(6);
	}

	static scalar_type const sqrt_3() {
		return sqrt(scalar_type(3));
	}
	static scalar_type const inv_sqrt_3() {
		return scalar_type(1) / sqrt(scalar_type(3));
	}
	static scalar_type const two_third() {
		return scalar_type(2) / scalar_type(3);
	}

	static scalar_type const pi() {
		return scalar_type(3.141592653589793238462643383279502884197169399375105820974944592307816406286);
	}
	static scalar_type const two_pi() {
		return 2 * this_type::pi();
	}
	static scalar_type const deg60() {
		return this_type::pi() / scalar_type(3);
	}
	static scalar_type const deg120() {
		return scalar_type(2) * this_type::pi() / scalar_type(3);
	}
	static scalar_type const deg240() {
		return scalar_type(4) * this_type::pi() / scalar_type(3);
	}

};

}
}

namespace color {

template< typename type_name >
using hsi = ::color::model< ::color::category::hsi< type_name > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct hue< ::color::category::hsi< tag_name > > {
public:
	typedef ::color::category::hsi< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace check {
namespace _internal {

template<>
struct integrity< ::color::category::hsi_float> {
public:
	typedef ::color::category::hsi_float category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			return false;
		}
		if(bound_type::template maximum<hue_p>() < m.template get<hue_p>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsi_double > {
public:
	typedef ::color::category::hsi_double category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			return false;
		}
		if(bound_type::template maximum<hue_p>() < m.template get<hue_p>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsi_ldouble > {
public:
	typedef ::color::category::hsi_ldouble category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		if(m.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			return false;
		}
		if(bound_type::template maximum<hue_p>() < m.template get<hue_p>()) {
			return false;
		}
		return true;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct saturation< ::color::category::hsi< tag_name > > {
public:
	typedef ::color::category::hsi< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct intensity< ::color::category::hsi< tag_name > > {
public:
	typedef ::color::category::hsi< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace check {
namespace _internal {

template< typename tag_name >
struct unique< ::color::category::hsi< tag_name > > {
public:
	typedef ::color::category::hsi< tag_name > category_type;

	typedef ::color::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		,intensity_p = ::color::place::_internal::intensity<category_type>::position_enum
	};

	static bool process(model_type const& m) {
		return true;
	}
};

}
}
}

namespace color {
namespace fix {
namespace _internal {
namespace _privateHSI {

template< typename category_name >
struct integrity {
public:
	typedef category_name category_type;

	typedef typename ::color::model<category_type> model_type;
	typedef typename ::color::trait::bound<category_type> bound_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
	};

	static void process(model_type &result) {
		if(result.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			result.template set<hue_p>(bound_type::template minimum<hue_p>());
			return;
		}
		if(bound_type::template maximum<hue_p>() < result.template get<hue_p>()) {
			result.template set<hue_p>(bound_type::template maximum<hue_p>());
			return;
		}
	}

	static void process(model_type &result, model_type const& right) {
		result = right;
		if(result.template get<hue_p>() < bound_type::template minimum<hue_p>()) {
			result.template set<hue_p>(bound_type::template minimum<hue_p>());
			return;
		}
		if(bound_type::template maximum<hue_p>() < result.template get<hue_p>()) {
			result.template set<hue_p>(bound_type::template maximum<hue_p>());
			return;
		}
	}

};

}

template<> struct integrity< ::color::category::hsi_float > : public ::color::fix::_internal::_privateHSI::integrity<::color::category::hsi_float > { };
template<> struct integrity< ::color::category::hsi_double > : public ::color::fix::_internal::_privateHSI::integrity<::color::category::hsi_double > { };
template<> struct integrity< ::color::category::hsi_ldouble > : public ::color::fix::_internal::_privateHSI::integrity<::color::category::hsi_ldouble> { };

}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsi<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::hsi<tag_name> > const& color_parameter) {
	typedef ::color::category::hsi<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::gray<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	enum { intensity_p = ::color::place::_internal::intensity<category_type>::position_enum };
	scalar_type g = normalize_type::template process<intensity_p >(color_parameter.template get<intensity_p >());
	return diverse_type::template process<0>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsi<tag_name> >::akin_type >::return_type
red(::color::model< ::color::category::hsi<tag_name> > const& color_parameter) {
	typedef ::color::category::hsi<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::hsi< category_type > hsi_constant_type;
	enum {
		red_p = ::color::place::_internal::red<akin_type>::position_enum
		,green_p = ::color::place::_internal::green<akin_type>::position_enum
		,blue_p = ::color::place::_internal::blue<akin_type>::position_enum
	};
	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		,intensity_p = ::color::place::_internal::intensity<category_type>::position_enum
	};
	scalar_type h = normalize_type::template process<hue_p >(color_parameter.template get<hue_p >());
	scalar_type s = normalize_type::template process<saturation_p>(color_parameter.template get<saturation_p>());
	scalar_type i = normalize_type::template process<intensity_p >(color_parameter.template get<intensity_p >());
	scalar_type min = i * (1 - s);
	int region = int(3 * h);
	h -= region * hsi_constant_type::third();
	h *= hsi_constant_type::two_pi();
	scalar_type n = i*(1+ s*cos(h) / cos(hsi_constant_type::deg60() - h));
	scalar_type r;
	scalar_type g;
	scalar_type b;
	switch(region % 3) {
	case 0:
		r = n;
		break;
	case 1:
		r = min;
		break;
	case 2:
		b = n;
		g = min;
		r = 3*i-(g+b);
		break;
	}
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsi<tag_name> >::akin_type >::return_type
green(::color::model< ::color::category::hsi<tag_name> > const& color_parameter) {
	typedef ::color::category::hsi<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::hsi< category_type > hsi_constant_type;
	enum {
		red_p = ::color::place::_internal::red<akin_type>::position_enum
		,green_p = ::color::place::_internal::green<akin_type>::position_enum
		,blue_p = ::color::place::_internal::blue<akin_type>::position_enum
	};
	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		,intensity_p = ::color::place::_internal::intensity<category_type>::position_enum
	};
	scalar_type h = normalize_type::template process<hue_p >(color_parameter.template get<hue_p >());
	scalar_type s = normalize_type::template process<saturation_p>(color_parameter.template get<saturation_p>());
	scalar_type i = normalize_type::template process<intensity_p >(color_parameter.template get<intensity_p >());
	scalar_type min = i * (1 - s);
	int region = int(3 * h);
	h -= region * hsi_constant_type::third();
	h *= hsi_constant_type::two_pi();
	scalar_type n = i*(1+ s*cos(h) / cos(hsi_constant_type::deg60() - h));
	scalar_type r;
	scalar_type g;
	scalar_type b;
	switch(region % 3) {
	case 0:
		r = n;
		b = min;
		g = 3*i-(r+b);
		break;
	case 1:
		g = n;
		break;
	case 2:
		g = min;
		break;
	}
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsi<tag_name> >::akin_type >::return_type
blue(::color::model< ::color::category::hsi<tag_name> > const& color_parameter) {
	typedef ::color::category::hsi<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::hsi< category_type > hsi_constant_type;
	enum {
		red_p = ::color::place::_internal::red<akin_type>::position_enum
		,green_p = ::color::place::_internal::green<akin_type>::position_enum
		,blue_p = ::color::place::_internal::blue<akin_type>::position_enum
	};
	enum {
		hue_p = ::color::place::_internal::hue<category_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_type>::position_enum
		,intensity_p = ::color::place::_internal::intensity<category_type>::position_enum
	};
	scalar_type h = normalize_type::template process<hue_p >(color_parameter.template get<hue_p >());
	scalar_type s = normalize_type::template process<saturation_p>(color_parameter.template get<saturation_p>());
	scalar_type i = normalize_type::template process<intensity_p >(color_parameter.template get<intensity_p >());
	scalar_type min = i * (1 - s);
	int region = int(3 * h);
	h -= region * hsi_constant_type::third();
	h *= hsi_constant_type::two_pi();
	scalar_type n = i*(1+ s*cos(h) / cos(hsi_constant_type::deg60() - h));
	scalar_type r;
	scalar_type g;
	scalar_type b;
	switch(region % 3) {
	case 0:
		b = min;
		break;
	case 1:
		g = n;
		r = min;
		b = 3*i-(r+g);
		break;
	case 2:
		b = n; ;
		break;
	}
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::hsi< tag_name> >::component_const_type
hue(::color::model< ::color::category::hsi< tag_name> > const& color_parameter) {
	typedef ::color::category::hsi< tag_name> category_type;
	enum { hue_p = ::color::place::_internal::hue<category_type>::position_enum };
	return color_parameter.template get<hue_p>();
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
hue
(
	::color::model< ::color::category::hsi< tag_name > > & color_parameter
	,typename ::color::model< ::color::category::hsi< tag_name > >::component_input_const_type component_parameter
) {
	typedef ::color::category::hsi< tag_name > category_type;
	enum { hue_p = ::color::place::_internal::hue< category_type >::position_enum };
	color_parameter.template set<hue_p>(component_parameter);
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::hsi< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsi< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsi< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<blue_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::hsi< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsi< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsi< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::hsi< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsi< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsi< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<red_p> (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::hsi< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsi< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::hsi< tag_name > category_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef double scalar_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	enum {
		intensity_p = ::color::place::_internal::intensity<category_type>::position_enum
	};
	color_parameter.template set<intensity_p>(reformat_type::template process<intensity_p,0>(component_parameter));
}

}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename gray_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		gray_p = ::color::place::_internal::gray<category_right_type>::position_enum
	};

	enum {
		hue_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		,intensity_p = ::color::place::_internal::intensity<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<hue_p>(left, bound_left_trait_type::template minimum<hue_p>());
		container_left_trait_type::template set<saturation_p>(left, bound_left_trait_type::template minimum<saturation_p>());
		container_left_trait_type::template set<intensity_p>(left, reformat_type::template process<intensity_p,0>(container_right_trait_type::template get<0>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > cmy_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmy_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< cmy_category_type > cmy_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(cmy_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::cmyk< cmyk_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmyk_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< cmyk_category_type > cmyk_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(cmyk_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::hsl< hsl_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsl_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< hsl_category_type > hsl_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(hsl_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< hsv_category_type > hsv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(hsv_model_type(right))).container();
	}
};

}
}
namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::hsi< tag_left_name >
	,::color::category::hsi< tag_right_name>
	> {
public:
	typedef ::color::category::hsi< tag_left_name > category_left_type;
	typedef ::color::category::hsi< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		hr_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,sr_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		,ir_p = ::color::place::_internal::intensity<category_left_type>::position_enum
	};

	enum {
		hl_p = ::color::place::_internal::hue<category_right_type>::position_enum
		,sl_p = ::color::place::_internal::saturation<category_right_type>::position_enum
		,il_p = ::color::place::_internal::intensity<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<hl_p>(left, reformat_type::template process<hl_p,hr_p>(container_right_trait_type::template get<hr_p>(right)));
		container_left_trait_type::template set<sl_p>(left, reformat_type::template process<sl_p,sr_p>(container_right_trait_type::template get<sr_p>(right)));
		container_left_trait_type::template set<il_p>(left, reformat_type::template process<il_p,ir_p>(container_right_trait_type::template get<ir_p>(right)));
	}
};
}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename rgb_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar<category_left_type> scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::hsi< category_right_type > hsi_constant_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		, intensity_p = ::color::place::_internal::intensity<category_left_type>::position_enum
	};

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		, blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type lo = std::min<scalar_type>({r,g,b});
		scalar_type h = 0;
		scalar_type i = (r + g + b) / scalar_type(3);
		scalar_type s = scalar_type(1) - lo / i;
		scalar_type c1 = r - g* scalar_type(0.5) - b * scalar_type(0.5);
		scalar_type c2 = (g-b) * hsi_constant_type::sqrt_3() * scalar_type(0.5);
		scalar_type thetaX = atan2(c2, c1);
		if(thetaX < 0) {
			thetaX += hsi_constant_type::two_pi();
		}
		h = thetaX;
		h /= hsi_constant_type::two_pi();
		container_left_trait_type::template set< hue_p>(left, diverse_type::template process< hue_p>(h));
		container_left_trait_type::template set<saturation_p>(left, diverse_type::template process<saturation_p>(s));
		container_left_trait_type::template set< intensity_p>(left, diverse_type::template process< intensity_p>(i));
	}
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::gray_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::gray_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::gray_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::gray_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::gray_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::gray_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::gray_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::cmyk_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::cmyk_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::cmyk_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::cmyk_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::cmyk_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::cmyk_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::cmyk_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::hsl_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::hsl_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::hsl_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::hsl_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::hsl_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::hsl_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::hsl_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::hsv_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::hsv_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::hsv_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::hsv_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::hsv_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::hsv_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::hsv_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::hsi_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::hsi_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::hsi_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::hsi_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::hsi_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::hsi_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::hsi_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct yiq< ::color::category::yiq< tag_name > > {
public:
	typedef ::color::category::yiq< tag_name > akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yiq< ::color::category::yuv_uint8 <reference_number> > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yiq< ::color::category::yuv_uint16 <reference_number> > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yiq< ::color::category::yuv_uint32 <reference_number> > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yiq< ::color::category::yuv_uint64 <reference_number> > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yiq< ::color::category::yuv_float <reference_number> > {
	typedef ::color::category::yiq_float akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yiq< ::color::category::yuv_double <reference_number> > {
	typedef ::color::category::yiq_double akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yiq< ::color::category::yuv_ldouble<reference_number> > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::YCgCo_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::YCgCo_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::YCgCo_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::YCgCo_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::YCgCo_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::YCgCo_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::YCgCo_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::YDbDr_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::YDbDr_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::YDbDr_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::YDbDr_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::YDbDr_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::YDbDr_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::YDbDr_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct yiq< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct yiq< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct yiq< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct yiq< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct yiq< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::yiq_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct yiq< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::yiq_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct yiq< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct xyz< ::color::category::xyz< tag_name > > {
public:
	typedef ::color::category::xyz< tag_name > akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::yiq_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::yiq_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::yiq_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::yiq_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::yiq_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::yiq_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::yiq_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct yiq_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 1, scalar_type(0.5957161349127745527), scalar_type(0.5225910452916111683) };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 1, scalar_type(0.5957161349127745527), scalar_type(0.5225910452916111683) };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, scalar_type(-0.5957161349127745527), scalar_type(-0.5225910452916111683) };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, scalar_type(-0.5957161349127745527), scalar_type(-0.5225910452916111683) };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 1, scalar_type(2*0.5957161349127745527), scalar_type(2 * 0.5225910452916111683) };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 1, scalar_type(2*0.5957161349127745527), scalar_type(2*0.5225910452916111683) };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yiq_float >
	: public ::color::_internal::utility::bound::yiq_scalar< unsigned, float > {
};

template< >
struct bound< ::color::category::yiq_double >
	: public ::color::_internal::utility::bound::yiq_scalar< unsigned, double > {
};

template< >
struct bound< ::color::category::yiq_ldouble >
	: public ::color::_internal::utility::bound::yiq_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yiq_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::yiq_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::yiq_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::yiq_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yiq_float >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< >
struct container< ::color::category::yiq_double >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< >
struct container< ::color::category::yiq_ldouble >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yiq_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< >
struct container< ::color::category::yiq_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< >
struct container< ::color::category::yiq_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< >
struct container< ::color::category::yiq_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {

template< typename type_name >
using yiq = ::color::model< typename ::color::category::yiq< type_name > >;

}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::yiq< tag_name> >::component_const_type
inphase(::color::model< ::color::category::yiq< tag_name> > const& color_parameter) {
	typedef ::color::category::yiq< tag_name> category_type;
	enum { inphase_p = ::color::place::_internal::inphase<category_type>::position_enum };
	return color_parameter.template get<inphase_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::yiq< tag_name> >::component_const_type
quadrature(::color::model< ::color::category::yiq< tag_name> > const& color_parameter) {
	typedef ::color::category::yiq< tag_name> category_type;
	enum { quadrature_p = ::color::place::_internal::quadrature<category_type>::position_enum };
	return color_parameter.template get<quadrature_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yiq<tag_name> >::akin_type >::return_type
red(::color::model< ::color::category::yiq<tag_name> > const& color_parameter) {
	typedef ::color::category::yiq<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::yiq<category_type> yiq_const_type;
	enum {
		luma_p = ::color::place::_internal::luma<category_type>::position_enum
		, inphase_p = ::color::place::_internal::inphase<category_type>::position_enum
		,quadrature_p = ::color::place::_internal::quadrature<category_type>::position_enum
	};
	enum {
		red_p = ::color::place::_internal::red<akin_type>::position_enum
	};
	static scalar_type a11 = yiq_const_type::a11(), a12 = yiq_const_type::a12(), a13 = yiq_const_type::a13();
	scalar_type y = normalize_type::template process< luma_p >(color_parameter.template get< luma_p>());
	scalar_type i = normalize_type::template process< inphase_p>(color_parameter.template get< inphase_p>());
	scalar_type q = normalize_type::template process<quadrature_p>(color_parameter.template get<quadrature_p>());
	i = (scalar_type(2) * i - scalar_type(1)) * yiq_const_type::i_max();
	q = (scalar_type(2) * q - scalar_type(1)) * yiq_const_type::q_max();
	scalar_type r = a11 * y + a12 * i + a13 * q;
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yiq<tag_name> >::akin_type >::return_type
green(::color::model< ::color::category::yiq<tag_name> > const& color_parameter) {
	typedef ::color::category::yiq<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::yiq<category_type> yiq_const_type;
	enum {
		luma_p = ::color::place::_internal::luma<category_type>::position_enum
		, inphase_p = ::color::place::_internal::inphase<category_type>::position_enum
		,quadrature_p = ::color::place::_internal::quadrature<category_type>::position_enum
	};
	enum {
		green_p = ::color::place::_internal::green<akin_type>::position_enum
	};
	static scalar_type a21 = yiq_const_type::a21(), a22 = yiq_const_type::a22(), a23 = yiq_const_type::a23();
	scalar_type y = normalize_type::template process< luma_p>(color_parameter.template get< luma_p>());
	scalar_type i = normalize_type::template process< inphase_p>(color_parameter.template get< inphase_p>());
	scalar_type q = normalize_type::template process<quadrature_p>(color_parameter.template get<quadrature_p>());
	i = (scalar_type(2) * i - scalar_type(1)) * yiq_const_type::i_max();
	q = (scalar_type(2) * q - scalar_type(1)) * yiq_const_type::q_max();
	scalar_type g = a21 * y + a22 * i + a23 * q;
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yiq<tag_name> >::akin_type >::return_type
blue(::color::model< ::color::category::yiq<tag_name> > const& color_parameter) {
	typedef ::color::category::yiq<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse<akin_type> diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::yiq<category_type> yiq_const_type;
	enum {
		luma_p = ::color::place::_internal::luma<category_type>::position_enum
		, inphase_p = ::color::place::_internal::inphase<category_type>::position_enum
		,quadrature_p = ::color::place::_internal::quadrature<category_type>::position_enum
	};
	enum {
		blue_p = ::color::place::_internal::blue<akin_type>::position_enum
	};
	static scalar_type a31 = yiq_const_type::a31(), a32 = yiq_const_type::a32(), a33 = yiq_const_type::a33();
	scalar_type y = normalize_type::template process< luma_p >(color_parameter.template get< luma_p>());
	scalar_type i = normalize_type::template process< inphase_p>(color_parameter.template get< inphase_p>());
	scalar_type q = normalize_type::template process<quadrature_p>(color_parameter.template get<quadrature_p>());
	i = (scalar_type(2) * i - scalar_type(1)) * yiq_const_type::i_max();
	q = (scalar_type(2) * q - scalar_type(1)) * yiq_const_type::q_max();
	scalar_type b = a31 * y + a32 * i + a33 * q;
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::yiq<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::yiq<tag_name> > const& color_parameter) {
	typedef ::color::category::yiq< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type > ::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<0,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::yiq< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::yiq< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::yiq< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< red_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::yiq< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::yiq< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::yiq< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::yiq< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::yiq< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::yiq< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<blue_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::yiq< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::yiq< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::yiq< tag_name > category_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef double scalar_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	enum {
		luma_p = ::color::place::_internal::luma<category_type>::position_enum
	};
	color_parameter.template set<luma_p>(reformat_type::template process<luma_p,0>(component_parameter));
}

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename gray_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		luma_p = ::color::place::_internal::luma<category_left_type>::position_enum
		, inphase_p = ::color::place::_internal::inphase<category_left_type>::position_enum
		,quadrature_p = ::color::place::_internal::quadrature<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type g = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		auto y = diverse_type::template process<0>(g);
		static auto const i = diverse_type::template process<1>(0.5);
		static auto const q = diverse_type::template process<2>(0.5);
		container_left_trait_type::template set<0>(left, y);
		container_left_trait_type::template set<1>(left, i);
		container_left_trait_type::template set<2>(left, q);
		container_left_trait_type::template set< luma_p>(left, y);
		container_left_trait_type::template set< inphase_p>(left, i);
		container_left_trait_type::template set<quadrature_p>(left, q);
	}

};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::constant::yiq< category_left_type > yiq_const_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		luma_p = ::color::place::_internal::luma<category_left_type>::position_enum
		, inphase_p = ::color::place::_internal::inphase<category_left_type>::position_enum
		,quadrature_p = ::color::place::_internal::quadrature<category_left_type>::position_enum
	};

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		,yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type b11 = yiq_const_type::b11(), b12 = yiq_const_type::b12(), b13 = yiq_const_type::b13();
		static scalar_type b21 = yiq_const_type::b21(), b22 = yiq_const_type::b22(), b23 = yiq_const_type::b23();
		static scalar_type b31 = yiq_const_type::b31(), b32 = yiq_const_type::b32(), b33 = yiq_const_type::b33();
		static scalar_type const b32n = -b32;
		scalar_type r = scalar_type(1) - normalize_type::template process<cyan_p >(container_right_trait_type::template get<cyan_p >(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<magenta_p>(container_right_trait_type::template get<magenta_p>(right));
		scalar_type b = scalar_type(1) - normalize_type::template process<yellow_p >(container_right_trait_type::template get<yellow_p >(right));
		scalar_type y = b11 * r + b12 * g + b13 * b;
		scalar_type i = b21 * r + b22 * g + b23 * b;
		scalar_type q = b31 * r + b32 * g + b33 * b;
		i = (i / b21 + scalar_type(1)) / scalar_type(2);
		q = (q / b32n + scalar_type(1)) / scalar_type(2);
		container_left_trait_type::template set< luma_p>(left, diverse_type::template process< luma_p>(y));
		container_left_trait_type::template set< inphase_p>(left, diverse_type::template process< inphase_p>(i));
		container_left_trait_type::template set<quadrature_p>(left, diverse_type::template process<quadrature_p>(q));
	}
};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::cmyk< cmyk_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_left_type;
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmyk_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yiq_category_type > yiq_model_type;
	typedef ::color::model< cmyk_category_type > cmyk_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yiq_model_type(rgb_model_type(cmyk_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::hsl< hsl_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsl_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yiq_category_type > yiq_model_type;
	typedef ::color::model< hsl_category_type > hsl_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yiq_model_type(rgb_model_type(hsl_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yiq_category_type > yiq_model_type;
	typedef ::color::model< hsv_category_type > hsv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yiq_model_type(rgb_model_type(hsv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename hsi_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::hsi< hsi_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_left_type;
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsi_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yiq_category_type > yiq_model_type;
	typedef ::color::model< hsi_category_type > hsi_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yiq_model_type(rgb_model_type(hsi_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename rgb_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::constant::yiq< category_left_type > yiq_const_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		luma_p = ::color::place::_internal::luma<category_left_type>::position_enum
		, inphase_p = ::color::place::_internal::inphase<category_left_type>::position_enum
		,quadrature_p = ::color::place::_internal::quadrature<category_left_type>::position_enum
	};

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type b11 = yiq_const_type::b11(), b12 = yiq_const_type::b12(), b13 = yiq_const_type::b13();
		static scalar_type b21 = yiq_const_type::b21(), b22 = yiq_const_type::b22(), b23 = yiq_const_type::b23();
		static scalar_type b31 = yiq_const_type::b31(), b32 = yiq_const_type::b32(), b33 = yiq_const_type::b33();
		static scalar_type const b32n = -b32;
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type y = b11 * r + b12 * g + b13 * b;
		scalar_type i = b21 * r + b22 * g + b23 * b;
		scalar_type q = b31 * r + b32 * g + b33 * b;
		i = (i / b21 + scalar_type(1)) / scalar_type(2);
		q = (q / b32n + scalar_type(1)) / scalar_type(2);
		container_left_trait_type::template set< luma_p>(left, diverse_type::template process< luma_p>(y));
		container_left_trait_type::template set< inphase_p>(left, diverse_type::template process< inphase_p>(i));
		container_left_trait_type::template set<quadrature_p>(left, diverse_type::template process<quadrature_p>(q));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::yiq< tag_left_name >
	,::color::category::yiq< tag_right_name>
	> {
public:
	typedef ::color::category::yiq< tag_left_name > category_left_type;
	typedef ::color::category::yiq< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		ll_p = ::color::place::_internal::luma<category_left_type>::position_enum
		,il_p = ::color::place::_internal::inphase<category_left_type>::position_enum
		,ql_p = ::color::place::_internal::quadrature<category_left_type>::position_enum
	};

	enum {
		lr_p = ::color::place::_internal::luma<category_right_type>::position_enum
		,ir_p = ::color::place::_internal::inphase<category_right_type>::position_enum
		,qr_p = ::color::place::_internal::quadrature<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<ll_p>(left, reformat_type::template process<ll_p,lr_p>(container_right_trait_type::template get<lr_p>(right)));
		container_left_trait_type::template set<il_p>(left, reformat_type::template process<il_p,ir_p>(container_right_trait_type::template get<ir_p>(right)));
		container_left_trait_type::template set<ql_p>(left, reformat_type::template process<ql_p,qr_p>(container_right_trait_type::template get<qr_p>(right)));
	}
};
}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::gray_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::gray_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::gray_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::gray_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::gray_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::gray_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::gray_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number > struct yuv< ::color::category::cmy_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number > struct yuv< ::color::category::cmy_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number > struct yuv< ::color::category::cmy_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number > struct yuv< ::color::category::cmy_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number > struct yuv< ::color::category::cmy_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number > struct yuv< ::color::category::cmy_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number > struct yuv< ::color::category::cmy_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::cmyk_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::cmyk_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::cmyk_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::cmyk_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::cmyk_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::cmyk_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::cmyk_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsl_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsl_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsl_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsl_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsl_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsl_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsl_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsv_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsv_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsv_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsv_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsv_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsv_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsv_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsi_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsi_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsi_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsi_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsi_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsi_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::hsi_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::rgb_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::rgb_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::rgb_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::rgb_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::rgb_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::rgb_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::rgb_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::yiq_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::yiq_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::yiq_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::yiq_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::yiq_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::yiq_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::yiq_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
struct yuv< ::color::category::yuv< tag_name, reference_number >, reference_number > {
public:
	typedef ::color::category::yuv< tag_name, reference_number > akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YCgCo_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YCgCo_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YCgCo_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YCgCo_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YCgCo_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YCgCo_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YCgCo_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YDbDr_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YDbDr_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YDbDr_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YDbDr_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YDbDr_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YDbDr_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::YDbDr_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::xyz_uint8 , reference_number > {
	typedef ::color::category::yuv_uint8 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::xyz_uint16 , reference_number > {
	typedef ::color::category::yuv_uint16 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::xyz_uint32 , reference_number > {
	typedef ::color::category::yuv_uint32 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::xyz_uint64 , reference_number > {
	typedef ::color::category::yuv_uint64 <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::xyz_float , reference_number > {
	typedef ::color::category::yuv_float <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::xyz_double , reference_number > {
	typedef ::color::category::yuv_double <reference_number> akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct yuv< ::color::category::xyz_ldouble, reference_number > {
	typedef ::color::category::yuv_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace trait {

template < ::color::constant::yuv::reference_enum reference_number > struct info< ::color::category::yuv_uint8 < reference_number > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::yuv::reference_enum reference_number > struct info< ::color::category::yuv_uint16 < reference_number > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::yuv::reference_enum reference_number > struct info< ::color::category::yuv_uint32 < reference_number > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::yuv::reference_enum reference_number > struct info< ::color::category::yuv_uint64 < reference_number > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::yuv::reference_enum reference_number > struct info< ::color::category::yuv_float < reference_number > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::yuv::reference_enum reference_number > struct info< ::color::category::yuv_double < reference_number > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::yuv::reference_enum reference_number > struct info< ::color::category::yuv_ldouble< reference_number > > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct yuv_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 1, scalar_type(0.436), scalar_type(0.615) };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 1, scalar_type(0.436), scalar_type(0.615) };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, scalar_type(-0.436), scalar_type(-0.615) };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, scalar_type(-0.436), scalar_type(-0.615) };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 1, scalar_type(2*0.436), scalar_type(2 * 0.615) };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 1, scalar_type(2*0.436), scalar_type(2*0.615) };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< ::color::constant::yuv::reference_enum reference_number >
struct bound< ::color::category::yuv_float<reference_number> >
	: public ::color::_internal::utility::bound::yuv_scalar< unsigned, float > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct bound< ::color::category::yuv_double< reference_number > >
	: public ::color::_internal::utility::bound::yuv_scalar< unsigned, double > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct bound< ::color::category::yuv_ldouble<reference_number> >
	: public ::color::_internal::utility::bound::yuv_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::yuv::reference_enum reference_number >
struct bound< ::color::category::yuv_uint8<reference_number> >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct bound< ::color::category::yuv_uint16<reference_number> >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct bound< ::color::category::yuv_uint32<reference_number> >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct bound< ::color::category::yuv_uint64< reference_number> >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::yuv::reference_enum reference_number >
struct component< ::color::category::yuv_float<reference_number> >
	: public ::color::_internal::utility::component::array< float, unsigned > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct component< ::color::category::yuv_double<reference_number> >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct component< ::color::category::yuv_ldouble<reference_number> >
	: public ::color::_internal::utility::component::array< long double, unsigned > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::yuv::reference_enum reference_number >
struct component< ::color::category::yuv_uint16<reference_number> >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct component< ::color::category::yuv_uint32<reference_number> >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct component< ::color::category::yuv_uint64<reference_number> >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct component< ::color::category::yuv_uint8< reference_number > >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::yuv::reference_enum reference_number >
struct container< ::color::category::yuv_float< reference_number > >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct container< ::color::category::yuv_double<reference_number> >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct container< ::color::category::yuv_ldouble<reference_number> >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::yuv::reference_enum reference_number >
struct container< ::color::category::yuv_uint8<reference_number> >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct container< ::color::category::yuv_uint16<reference_number> >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct container< ::color::category::yuv_uint32< reference_number> >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< ::color::constant::yuv::reference_enum reference_number >
struct container< ::color::category::yuv_uint64< reference_number > >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {
namespace constant {
namespace yuv {

namespace _internal {

template< typename scalar_name, ::color::constant::yuv::reference_enum reference_number = ::color::constant::yuv::error_entity >
struct base {
	typedef scalar_name scalar_type;
	static scalar_type const Wr() {
		return 0;
	}
	static scalar_type const Wb() {
		return 0;
	}
	static scalar_type const Wg() {
		return 0;
	}
	static scalar_type const Umax() {
		return 0;
	}
	static scalar_type const Vmax() {
		return 0;
	}
};

template< typename scalar_name >
struct base< scalar_name, ::color::constant::yuv::BT_601_entity > {
	typedef scalar_name scalar_type;
	typedef ::color::constant::yuv::_internal::base< scalar_name, ::color::constant::yuv::BT_601_entity > this_type;

	static scalar_type const Wr() {
		return 0.2988390;
	}
	static scalar_type const Wb() {
		return 0.1143500;
	}
	static scalar_type const Wg() {
		return 1 - this_type::Wr() - this_type::Wb();
	}
	static scalar_type const Umax() {
		return 0.436;
	}
	static scalar_type const Vmax() {
		return 0.615;
	}
};

template< typename scalar_name >
struct base< scalar_name, ::color::constant::yuv::BT_709_entity > {
	typedef scalar_name scalar_type;
	typedef ::color::constant::yuv::_internal::base< scalar_name, ::color::constant::yuv::BT_709_entity > this_type;

	static scalar_type const Wr() {
		return 0.2126729;
	}
	static scalar_type const Wb() {
		return 0.0721750;
	}
	static scalar_type const Wg() {
		return 1 - this_type::Wr() - this_type::Wb();
	}
	static scalar_type const Umax() {
		return 0.436;
	}
	static scalar_type const Vmax() {
		return 0.615;
	}
};
}

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
struct parameter
	: public ::color::constant::yuv::_internal::base< typename ::color::trait::scalar< ::color::category::yuv< tag_name, reference_number > >::instance_type, reference_number > {
public:
	typedef ::color::category::yuv< tag_name, reference_number > category_type;

	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;

	typedef ::color::constant::yuv::parameter<tag_name,reference_number> this_type;

	static scalar_type const u_min() {
		return -this_type::Umax();
	}
	static scalar_type const u_max() {
		return this_type::Umax();
	}
	static scalar_type const u_range() {
		return 2*this_type::Umax();
	}

	static scalar_type const v_min() {
		return -this_type::Vmax();
	}
	static scalar_type const v_max() {
		return this_type::Vmax();
	}
	static scalar_type const v_range() {
		return 2*this_type::Vmax();
	}

	static scalar_type u_diverse(scalar_type const& normal) {
		return this_type::u_range() * normal + this_type::u_min();
	}
	static scalar_type u_normalize(scalar_type const& divert) {
		return (divert - this_type::u_min()) /this_type::u_range();
	}

	static scalar_type v_diverse(scalar_type const& normal) {
		return this_type::v_range() * normal + this_type::v_min();
	}
	static scalar_type v_normalize(scalar_type const& divert) {
		return (divert - this_type::v_min()) /this_type::v_range();
	}
};

}
}
}

namespace color {

template< typename type_name, ::color::constant::yuv::reference_enum reference_number = ::color::constant::yuv::BT_709_entity >
using yuv = ::color::model< typename ::color::category::yuv< type_name, reference_number > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
struct luma< ::color::category::yuv< tag_name, reference_number > > {
public:
	typedef ::color::category::yuv< tag_name, reference_number > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace get {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::yuv<tag_name,reference_number> >::akin_type >::return_type
gray(::color::model< ::color::category::yuv<tag_name, reference_number> > const& color_parameter) {
	typedef ::color::category::yuv< tag_name, reference_number > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<0,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yuv<tag_name,reference_number> >::akin_type >::return_type
red(::color::model< ::color::category::yuv<tag_name,reference_number> > const& color_parameter) {
	typedef ::color::category::yuv< tag_name, reference_number > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::yuv::parameter< tag_name, reference_number > yuv_parameter_type;
	static scalar_type const Wr = yuv_parameter_type::Wr();
	static scalar_type const Vmax = yuv_parameter_type::Vmax();
	static scalar_type const b11 = 1, b12 = 0, b13 = (1 - Wr) / Vmax;
	scalar_type y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type v = normalize_type::template process<2>(color_parameter.template get<2>());
	v = (v - scalar_type(0.5)) * scalar_type(2) * Vmax;
	scalar_type r = y + v * b13;
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yuv<tag_name,reference_number> >::akin_type >::return_type
green(::color::model< ::color::category::yuv<tag_name, reference_number> > const& color_parameter) {
	typedef ::color::category::yuv<tag_name, reference_number> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::yuv::parameter< tag_name, reference_number > yuv_parameter_type;
	static scalar_type const Wr = yuv_parameter_type::Wr();
	static scalar_type const Wb = yuv_parameter_type::Wb();
	static scalar_type const Wg = yuv_parameter_type::Wg();
	static scalar_type const Umax = yuv_parameter_type::Umax();
	static scalar_type const Vmax = yuv_parameter_type::Vmax();
	static scalar_type const b21 = 1, b22 = - Wb*(1 - Wb) / Umax / Wg, b23 = -Wr*(1 - Wr) / Vmax / Wg;
	scalar_type y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type u = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type v = normalize_type::template process<2>(color_parameter.template get<2>());
	u = (u - scalar_type(0.5)) * scalar_type(2) * Umax;
	v = (v - scalar_type(0.5)) * scalar_type(2) * Vmax;
	scalar_type g = y + u * b22 + v * b23;
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yuv<tag_name,reference_number> >::akin_type >::return_type
blue(::color::model< ::color::category::yuv<tag_name,reference_number> > const& color_parameter) {
	typedef ::color::category::yuv<tag_name,reference_number> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::yuv::parameter< tag_name,reference_number > yuv_parameter_type;
	static scalar_type const Wb = yuv_parameter_type::Wb();
	static scalar_type const Umax = yuv_parameter_type::Umax();
	static scalar_type const b31 = 1, b32 = ((1 - Wb) / Umax), b33 = 0;
	scalar_type y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type u = normalize_type::template process<1>(color_parameter.template get<1>());
	u = (u - scalar_type(0.5)) * scalar_type(2) * Umax;
	scalar_type b = y + u * b32;
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace set {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
inline
void
blue
(
	::color::model< ::color::category::yuv< tag_name, reference_number > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::yuv< tag_name,reference_number > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::yuv< tag_name, reference_number > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	::color::model< akin_type > rgb_instance(color_parameter);
	rgb_instance.template set<blue_p > (component_parameter);
	color_parameter = rgb_instance;
}

}
}

namespace color {
namespace set {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
inline
void
green
(
	::color::model< ::color::category::yuv< tag_name, reference_number > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::yuv< tag_name, reference_number > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::yuv< tag_name, reference_number > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
inline
void
red
(
	::color::model< ::color::category::yuv< tag_name,reference_number > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::yuv< tag_name,reference_number > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::yuv< tag_name,reference_number > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<red_p> (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name, ::color::constant::yuv::reference_enum reference_number >
inline
void
gray
(
	::color::model< ::color::category::yuv< tag_name, reference_number > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::yuv< tag_name, reference_number > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::yuv< tag_name, reference_number > category_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef double scalar_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	color_parameter.template set<0>(reformat_type::template process<0,0>(component_parameter));
}

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name , ::color::constant::yuv::reference_enum yuv_reference_number
	,typename gray_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type g = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		auto y = diverse_type::template process<0>(g);
		static auto const u = diverse_type::template process<1>(0.5);
		static auto const v = diverse_type::template process<2>(0.5);
		container_left_trait_type::template set<0>(left, y);
		container_left_trait_type::template set<1>(left, u);
		container_left_trait_type::template set<2>(left, v);
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name , ::color::constant::yuv::reference_enum yuv_reference_number
	,typename cmy_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::yuv::parameter< yuv_tag_name, yuv_reference_number > yuv_parameter_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		,yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type const Wr = yuv_parameter_type::Wr();
		static scalar_type const Wb = yuv_parameter_type::Wb();
		static scalar_type const Wg = yuv_parameter_type::Wg();
		static scalar_type const Umax = yuv_parameter_type::Umax();
		static scalar_type const Vmax = yuv_parameter_type::Vmax();
		scalar_type r = scalar_type(1) - normalize_type::template process<cyan_p >(container_right_trait_type::template get<cyan_p >(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<magenta_p >(container_right_trait_type::template get<magenta_p >(right));
		scalar_type b = scalar_type(1) - normalize_type::template process<yellow_p >(container_right_trait_type::template get<yellow_p >(right));
		scalar_type y = Wr * r + Wg * g + Wb * b;
		scalar_type u = ((b - y) / (1 - Wb) + scalar_type(1)) / scalar_type(2);
		scalar_type v = ((r - y) / (1 - Wr) + scalar_type(1)) / scalar_type(2);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(u));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(v));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name , ::color::constant::yuv::reference_enum yuv_reference_number
	,typename cmyk_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::cmyk< cmyk_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_left_type;
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmyk_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yuv_category_type > yuv_model_type;
	typedef ::color::model< cmyk_category_type > cmyk_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yuv_model_type(rgb_model_type(cmyk_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	, typename hsl_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::hsl< hsl_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsl_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yuv_category_type > yuv_model_type;
	typedef ::color::model< hsl_category_type > hsl_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yuv_model_type(rgb_model_type(hsl_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	,typename hsv_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yuv_category_type > yuv_model_type;
	typedef ::color::model< hsv_category_type > hsv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yuv_model_type(rgb_model_type(hsv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	,typename hsi_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::hsi< hsi_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_left_type;
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsi_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yuv_category_type > yuv_model_type;
	typedef ::color::model< hsi_category_type > hsi_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yuv_model_type(rgb_model_type(hsi_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {
template
<
	typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	,typename rgb_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::yuv::parameter< yuv_tag_name, yuv_reference_number > yuv_parameter_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_right_type>::position_enum
			,green_p = ::color::place::_internal::green<category_right_type>::position_enum
			,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		static scalar_type const Wr = yuv_parameter_type::Wr();
		static scalar_type const Wb = yuv_parameter_type::Wb();
		static scalar_type const Wg = yuv_parameter_type::Wg();
		static scalar_type const Umax = yuv_parameter_type::Umax();
		static scalar_type const Vmax = yuv_parameter_type::Vmax();
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type y = Wr * r + Wg * g + Wb * b;
		scalar_type u = ((b - y) / (1 - Wb) + scalar_type(1)) / scalar_type(2);
		scalar_type v = ((r - y) / (1 - Wr) + scalar_type(1)) / scalar_type(2);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(u));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(v));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	,typename yiq_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_left_type;
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yiq_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yuv_category_type > yuv_model_type;
	typedef ::color::model< yiq_category_type > yiq_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yuv_model_type(rgb_model_type(yiq_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename tag_left_name, ::color::constant::yuv::reference_enum left_reference_number
	,typename tag_right_name, ::color::constant::yuv::reference_enum right_reference_number
	>
struct convert
	<
	::color::category::yuv< tag_left_name, left_reference_number >
	,::color::category::yuv< tag_right_name, right_reference_number>
	> {
public:
	typedef ::color::category::yuv< tag_left_name , left_reference_number > category_left_type;
	typedef ::color::category::yuv< tag_right_name, right_reference_number > category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace akin {

template< typename category_name >
struct YCgCo {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YCgCo< ::color::category::cmy_uint8 > {
	typedef ::color::category::YCgCo_uint8 akin_type;
};
template< >struct YCgCo< ::color::category::cmy_uint16 > {
	typedef ::color::category::YCgCo_uint16 akin_type;
};
template< >struct YCgCo< ::color::category::cmy_uint32 > {
	typedef ::color::category::YCgCo_uint32 akin_type;
};
template< >struct YCgCo< ::color::category::cmy_uint64 > {
	typedef ::color::category::YCgCo_uint64 akin_type;
};
template< >struct YCgCo< ::color::category::cmy_float > {
	typedef ::color::category::YCgCo_float akin_type;
};
template< >struct YCgCo< ::color::category::cmy_double > {
	typedef ::color::category::YCgCo_double akin_type;
};
template< >struct YCgCo< ::color::category::cmy_ldouble > {
	typedef ::color::category::YCgCo_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YCgCo< ::color::category::cmyk_uint8 > {
	typedef ::color::category::YCgCo_uint8 akin_type;
};
template< >struct YCgCo< ::color::category::cmyk_uint16 > {
	typedef ::color::category::YCgCo_uint16 akin_type;
};
template< >struct YCgCo< ::color::category::cmyk_uint32 > {
	typedef ::color::category::YCgCo_uint32 akin_type;
};
template< >struct YCgCo< ::color::category::cmyk_uint64 > {
	typedef ::color::category::YCgCo_uint64 akin_type;
};
template< >struct YCgCo< ::color::category::cmyk_float > {
	typedef ::color::category::YCgCo_float akin_type;
};
template< >struct YCgCo< ::color::category::cmyk_double > {
	typedef ::color::category::YCgCo_double akin_type;
};
template< >struct YCgCo< ::color::category::cmyk_ldouble > {
	typedef ::color::category::YCgCo_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YCgCo< ::color::category::gray_uint8 > {
	typedef ::color::category::YCgCo_uint8 akin_type;
};
template< >struct YCgCo< ::color::category::gray_uint16 > {
	typedef ::color::category::YCgCo_uint16 akin_type;
};
template< >struct YCgCo< ::color::category::gray_uint32 > {
	typedef ::color::category::YCgCo_uint32 akin_type;
};
template< >struct YCgCo< ::color::category::gray_uint64 > {
	typedef ::color::category::YCgCo_uint64 akin_type;
};
template< >struct YCgCo< ::color::category::gray_float > {
	typedef ::color::category::YCgCo_float akin_type;
};
template< >struct YCgCo< ::color::category::gray_double > {
	typedef ::color::category::YCgCo_double akin_type;
};
template< >struct YCgCo< ::color::category::gray_ldouble > {
	typedef ::color::category::YCgCo_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YCgCo< ::color::category::hsl_uint8 > {
	typedef ::color::category::YCgCo_uint8 akin_type;
};
template< >struct YCgCo< ::color::category::hsl_uint16 > {
	typedef ::color::category::YCgCo_uint16 akin_type;
};
template< >struct YCgCo< ::color::category::hsl_uint32 > {
	typedef ::color::category::YCgCo_uint32 akin_type;
};
template< >struct YCgCo< ::color::category::hsl_uint64 > {
	typedef ::color::category::YCgCo_uint64 akin_type;
};
template< >struct YCgCo< ::color::category::hsl_float > {
	typedef ::color::category::YCgCo_float akin_type;
};
template< >struct YCgCo< ::color::category::hsl_double > {
	typedef ::color::category::YCgCo_double akin_type;
};
template< >struct YCgCo< ::color::category::hsl_ldouble > {
	typedef ::color::category::YCgCo_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YCgCo< ::color::category::hsv_uint8 > {
	typedef ::color::category::YCgCo_uint8 akin_type;
};
template< >struct YCgCo< ::color::category::hsv_uint16 > {
	typedef ::color::category::YCgCo_uint16 akin_type;
};
template< >struct YCgCo< ::color::category::hsv_uint32 > {
	typedef ::color::category::YCgCo_uint32 akin_type;
};
template< >struct YCgCo< ::color::category::hsv_uint64 > {
	typedef ::color::category::YCgCo_uint64 akin_type;
};
template< >struct YCgCo< ::color::category::hsv_float > {
	typedef ::color::category::YCgCo_float akin_type;
};
template< >struct YCgCo< ::color::category::hsv_double > {
	typedef ::color::category::YCgCo_double akin_type;
};
template< >struct YCgCo< ::color::category::hsv_ldouble > {
	typedef ::color::category::YCgCo_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YCgCo< ::color::category::rgb_uint8 > {
	typedef ::color::category::YCgCo_uint8 akin_type;
};
template< >struct YCgCo< ::color::category::rgb_uint16 > {
	typedef ::color::category::YCgCo_uint16 akin_type;
};
template< >struct YCgCo< ::color::category::rgb_uint32 > {
	typedef ::color::category::YCgCo_uint32 akin_type;
};
template< >struct YCgCo< ::color::category::rgb_uint64 > {
	typedef ::color::category::YCgCo_uint64 akin_type;
};
template< >struct YCgCo< ::color::category::rgb_float > {
	typedef ::color::category::YCgCo_float akin_type;
};
template< >struct YCgCo< ::color::category::rgb_double > {
	typedef ::color::category::YCgCo_double akin_type;
};
template< >struct YCgCo< ::color::category::rgb_ldouble > {
	typedef ::color::category::YCgCo_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YCgCo< ::color::category::yiq_uint8 > {
	typedef ::color::category::YCgCo_uint8 akin_type;
};
template< >struct YCgCo< ::color::category::yiq_uint16 > {
	typedef ::color::category::YCgCo_uint16 akin_type;
};
template< >struct YCgCo< ::color::category::yiq_uint32 > {
	typedef ::color::category::YCgCo_uint32 akin_type;
};
template< >struct YCgCo< ::color::category::yiq_uint64 > {
	typedef ::color::category::YCgCo_uint64 akin_type;
};
template< >struct YCgCo< ::color::category::yiq_float > {
	typedef ::color::category::YCgCo_float akin_type;
};
template< >struct YCgCo< ::color::category::yiq_double > {
	typedef ::color::category::YCgCo_double akin_type;
};
template< >struct YCgCo< ::color::category::yiq_ldouble > {
	typedef ::color::category::YCgCo_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct YCgCo< ::color::category::YCgCo< tag_name > > {
public:
	typedef ::color::category::YCgCo< tag_name > akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YCgCo< ::color::category::xyz_uint8 > {
	typedef ::color::category::YCgCo_uint8 akin_type;
};
template< >struct YCgCo< ::color::category::xyz_uint16 > {
	typedef ::color::category::YCgCo_uint16 akin_type;
};
template< >struct YCgCo< ::color::category::xyz_uint32 > {
	typedef ::color::category::YCgCo_uint32 akin_type;
};
template< >struct YCgCo< ::color::category::xyz_uint64 > {
	typedef ::color::category::YCgCo_uint64 akin_type;
};
template< >struct YCgCo< ::color::category::xyz_float > {
	typedef ::color::category::YCgCo_float akin_type;
};
template< >struct YCgCo< ::color::category::xyz_double > {
	typedef ::color::category::YCgCo_double akin_type;
};
template< >struct YCgCo< ::color::category::xyz_ldouble > {
	typedef ::color::category::YCgCo_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::YCgCo_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YCgCo_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YCgCo_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YCgCo_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YCgCo_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YCgCo_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YCgCo_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct YCgCo_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 1, 0.5, 0.5 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 1, 0.5, 0.5 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, -0.5, -0.5 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, -0.5, -0.5 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 1, 1, 1 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 1, 1, 1 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::YCgCo_float >
	: public ::color::_internal::utility::bound::YCgCo_scalar< unsigned, float > {
};

template< >
struct bound< ::color::category::YCgCo_double >
	: public ::color::_internal::utility::bound::YCgCo_scalar< unsigned, double > {
};

template< >
struct bound< ::color::category::YCgCo_ldouble >
	: public ::color::_internal::utility::bound::YCgCo_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::YCgCo_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::YCgCo_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::YCgCo_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::YCgCo_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::YCgCo_float >
	: public ::color::_internal::utility::component::array< float, unsigned > {
};

template< >
struct component< ::color::category::YCgCo_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::YCgCo_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::YCgCo_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::YCgCo_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::YCgCo_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::YCgCo_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::YCgCo_float >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< >
struct container< ::color::category::YCgCo_double >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< >
struct container< ::color::category::YCgCo_ldouble >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::YCgCo_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< >
struct container< ::color::category::YCgCo_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< >
struct container< ::color::category::YCgCo_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< >
struct container< ::color::category::YCgCo_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {
namespace constant {

template< typename category_name >
struct YCgCo {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::YCgCo<category_type> this_type;

	static scalar_type const half() {
		return 0.5;
	}
	static scalar_type const one() {
		return 1;
	}

	static scalar_type const Cg_min() {
		return -0.5;
	}
	static scalar_type const Cg_max() {
		return 0.5;
	}
	static scalar_type const Cg_range() {
		return 1;
	}

	static scalar_type const Co_min() {
		return -0.5;
	}
	static scalar_type const Co_max() {
		return 0.5;
	}
	static scalar_type const Co_range() {
		return 1;
	}

	static scalar_type Cg_diverse(scalar_type const& normal) {
		return this_type::Cg_range() * normal + this_type::Cg_min();
	}
	static scalar_type Cg_normalize(scalar_type const& divert) {
		return (divert - this_type::Cg_min()) /this_type::Cg_range();
	}

	static scalar_type Co_diverse(scalar_type const& normal) {
		return this_type::Co_range() * normal + this_type::Co_min();
	}
	static scalar_type Co_normalize(scalar_type const& divert) {
		return (divert - this_type::Co_min()) /this_type::Co_range();
	}

};

}
}

namespace color {

template< typename type_name >
using YCgCo = ::color::model< typename ::color::category::YCgCo< type_name > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct luma< ::color::category::YCgCo< tag_name > > {
public:
	typedef ::color::category::YCgCo< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::YCgCo<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::YCgCo<tag_name> > const& color_parameter) {
	typedef ::color::category::YCgCo< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::gray<category_type>::akin_type akin_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<0,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::YCgCo<tag_name> >::akin_type >::return_type
red(::color::model< ::color::category::YCgCo<tag_name> > const& color_parameter) {
	typedef ::color::category::YCgCo< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::trait::container<category_type> container_trait_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::YCgCo< category_type > YCgCo_const_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	scalar_type Y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type Cg = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type Co = normalize_type::template process<2>(color_parameter.template get<2>());
	Cg = YCgCo_const_type::Cg_diverse(Cg);
	Co = YCgCo_const_type::Co_diverse(Co);
	scalar_type r = Y - Cg + Co;
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::YCgCo<tag_name> >::akin_type >::return_type
green(::color::model< ::color::category::YCgCo<tag_name> > const& color_parameter) {
	typedef ::color::category::YCgCo<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef typename ::color::trait::container<category_type> container_trait_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::YCgCo< category_type > YCgCo_const_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	scalar_type Y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type Cg = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type Co = normalize_type::template process<2>(color_parameter.template get<2>());
	Cg = YCgCo_const_type::Cg_diverse(Cg);
	Co = YCgCo_const_type::Co_diverse(Co);
	scalar_type g = Y + Cg;
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::YCgCo<tag_name> >::akin_type >::return_type
blue(::color::model< ::color::category::YCgCo<tag_name> > const& color_parameter) {
	typedef ::color::category::YCgCo<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::trait::container<category_type> container_trait_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::YCgCo< category_type > YCgCo_const_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	scalar_type Y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type Cg = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type Co = normalize_type::template process<2>(color_parameter.template get<2>());
	Cg = YCgCo_const_type::Cg_diverse(Cg);
	Co = YCgCo_const_type::Co_diverse(Co);
	scalar_type b = Y - Cg - Co;
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::YCgCo< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YCgCo< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YCgCo< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	::color::model< akin_type > rgb_instance(color_parameter);
	rgb_instance.template set<blue_p > (component_parameter);
	color_parameter = rgb_instance;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::YCgCo< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YCgCo< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YCgCo< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::YCgCo< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YCgCo< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YCgCo< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<red_p> (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::YCgCo< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::YCgCo< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YCgCo< tag_name > category_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef double scalar_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	color_parameter.template set<0>(reformat_type::template process<0,0>(component_parameter));
}

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename gray_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type g = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		auto Y = diverse_type::template process<0>(g);
		static auto const Cg = diverse_type::template process<1>(0.5);
		static auto const Co = diverse_type::template process<2>(0.5);
		container_left_trait_type::template set<0>(left, Y);
		container_left_trait_type::template set<1>(left, Cg);
		container_left_trait_type::template set<2>(left, Co);
	}
};

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::YCgCo< category_left_type > YCgCo_const_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		,yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = scalar_type(1) - normalize_type::template process<cyan_p >(container_right_trait_type::template get<cyan_p >(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<magenta_p >(container_right_trait_type::template get<magenta_p >(right));
		scalar_type b = scalar_type(1) - normalize_type::template process<yellow_p >(container_right_trait_type::template get<yellow_p >(right));
		scalar_type Y = 0.25 * r + 0.5 * g + 0.25 * b;
		scalar_type Cg = -0.25 * r + 0.5 * g - 0.25 * b;
		scalar_type Co = 0.5 * r + 0.0 * g - 0.5 * b;
		Cg = YCgCo_const_type::Cg_normalize(Cg);
		Co = YCgCo_const_type::Co_normalize(Co);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(Y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(Cg));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(Co));
	}
};

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::cmyk< cmyk_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_left_type;
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmyk_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;
	typedef ::color::model< cmyk_category_type > cmyk_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YCgCo_model_type(rgb_model_type(cmyk_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::hsl< hsl_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsl_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;
	typedef ::color::model< hsl_category_type > hsl_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YCgCo_model_type(rgb_model_type(hsl_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;
	typedef ::color::model< hsv_category_type > hsv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YCgCo_model_type(rgb_model_type(hsv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename hsi_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::hsi< hsi_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_left_type;
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsi_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;
	typedef ::color::model< hsi_category_type > hsi_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YCgCo_model_type(rgb_model_type(hsi_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename rgb_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::YCgCo< category_left_type > YCgCo_const_type;

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type Y = 0.25 * r + 0.5 * g + 0.25 * b;
		scalar_type Cg = -0.25 * r + 0.5 * g - 0.25 * b;
		scalar_type Co = 0.5 * r + 0.0 * g - 0.5 * b;
		Cg = YCgCo_const_type::Cg_normalize(Cg);
		Co = YCgCo_const_type::Co_normalize(Co);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(Y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(Cg));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(Co));
	}
};

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename yiq_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_left_type;
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yiq_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;
	typedef ::color::model< yiq_category_type > yiq_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YCgCo_model_type(rgb_model_type(yiq_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YCgCo_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	>
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::yuv< yuv_tag_name, yuv_reference_number >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_left_type;
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yuv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;
	typedef ::color::model< yuv_category_type > yuv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YCgCo_model_type(rgb_model_type(yuv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::YCgCo< tag_left_name >
	,::color::category::YCgCo< tag_right_name>
	> {
public:
	typedef ::color::category::YCgCo< tag_left_name > category_left_type;
	typedef ::color::category::YCgCo< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace akin {

template< typename category_name >
struct YDbDr {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::gray_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::gray_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::gray_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::gray_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::gray_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::gray_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::gray_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::cmy_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::cmy_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::cmy_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::cmy_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::cmy_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::cmy_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::cmy_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::cmyk_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::cmyk_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::cmyk_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::cmyk_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::cmyk_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::cmyk_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::cmyk_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::hsl_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::hsl_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::hsl_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::hsl_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::hsl_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::hsl_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::hsl_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::hsv_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::hsv_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::hsv_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::hsv_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::hsv_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::hsv_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::hsv_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::hsi_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::hsi_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::hsi_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::hsi_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::hsi_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::hsi_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::hsi_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::rgb_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::rgb_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::rgb_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::rgb_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::rgb_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::rgb_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::rgb_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::yiq_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::yiq_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::yiq_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::yiq_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::yiq_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::yiq_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::yiq_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct YDbDr< ::color::category::yuv_uint8 <reference_number> > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct YDbDr< ::color::category::yuv_uint16 <reference_number> > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct YDbDr< ::color::category::yuv_uint32 <reference_number> > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct YDbDr< ::color::category::yuv_uint64 <reference_number> > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct YDbDr< ::color::category::yuv_float <reference_number> > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct YDbDr< ::color::category::yuv_double <reference_number> > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct YDbDr< ::color::category::yuv_ldouble<reference_number> > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::YCgCo_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::YCgCo_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::YCgCo_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::YCgCo_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::YCgCo_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::YCgCo_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::YCgCo_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name >
struct YDbDr< ::color::category::YDbDr< tag_name > > {
public:
	typedef ::color::category::YDbDr< tag_name > akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YDbDr< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YDbDr< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YDbDr< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YDbDr< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YDbDr< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YDbDr< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YDbDr< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct YDbDr< ::color::category::xyz_uint8 > {
	typedef ::color::category::YDbDr_uint8 akin_type;
};
template< >struct YDbDr< ::color::category::xyz_uint16 > {
	typedef ::color::category::YDbDr_uint16 akin_type;
};
template< >struct YDbDr< ::color::category::xyz_uint32 > {
	typedef ::color::category::YDbDr_uint32 akin_type;
};
template< >struct YDbDr< ::color::category::xyz_uint64 > {
	typedef ::color::category::YDbDr_uint64 akin_type;
};
template< >struct YDbDr< ::color::category::xyz_float > {
	typedef ::color::category::YDbDr_float akin_type;
};
template< >struct YDbDr< ::color::category::xyz_double > {
	typedef ::color::category::YDbDr_double akin_type;
};
template< >struct YDbDr< ::color::category::xyz_ldouble > {
	typedef ::color::category::YDbDr_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::YDbDr_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YDbDr_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YDbDr_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YDbDr_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YDbDr_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YDbDr_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::YDbDr_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct YDbDr_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 1, scalar_type(1.333), scalar_type(1.333) };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 1, scalar_type(1.333), scalar_type(1.333) };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, scalar_type(-1.333), scalar_type(-1.333) };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, scalar_type(-1.333), scalar_type(-1.333) };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 1, scalar_type(2.666), scalar_type(2.666) };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 1, scalar_type(2.666), scalar_type(2.666) };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::YDbDr_float >
	: public ::color::_internal::utility::bound::YDbDr_scalar< unsigned, float > {
};

template< >
struct bound< ::color::category::YDbDr_double >
	: public ::color::_internal::utility::bound::YDbDr_scalar< unsigned, double > {
};

template< >
struct bound< ::color::category::YDbDr_ldouble >
	: public ::color::_internal::utility::bound::YDbDr_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::YDbDr_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::YDbDr_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::YDbDr_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::YDbDr_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::YDbDr_float >
	: public ::color::_internal::utility::component::array< float, unsigned > {
};

template< >
struct component< ::color::category::YDbDr_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::YDbDr_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::YDbDr_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::YDbDr_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::YDbDr_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::YDbDr_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::YDbDr_float >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< >
struct container< ::color::category::YDbDr_double >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< >
struct container< ::color::category::YDbDr_ldouble >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::YDbDr_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< >
struct container< ::color::category::YDbDr_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< >
struct container< ::color::category::YDbDr_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< >
struct container< ::color::category::YDbDr_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {
namespace constant {

template< typename category_name >
struct YDbDr {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::YDbDr<category_type> this_type;

	static scalar_type const one() {
		return 1;
	}

	static scalar_type const Wr() {
		return 0.298839;
	}
	static scalar_type const Wb() {
		return 0.114350;
	}
	static scalar_type const Wg() {
		return this_type::one() - this_type::Wr()-this_type::Wb();
	}
	static scalar_type const Umax() {
		return 0.436;
	}
	static scalar_type const Vmax() {
		return 0.615;
	}

	static scalar_type const DB_scale() {
		return +3.059;
	}
	static scalar_type const DR_scale() {
		return -2.169;
	}

	static scalar_type const DB_min() {
		return - this_type::Umax() * this_type::DR_scale();
	}
	static scalar_type const DB_max() {
		return this_type::Umax() * this_type::DR_scale();
	}
	static scalar_type const DB_range() {
		return this_type::DB_max() - this_type::DB_min();
	}

	static scalar_type const DR_min() {
		return this_type::Umax() * this_type::DR_scale();
	}
	static scalar_type const DR_max() {
		return - this_type::Umax() * this_type::DR_scale();
	}
	static scalar_type const DR_range() {
		return this_type::DR_max() - this_type::DR_min();
	}

	static scalar_type DB_diverse(scalar_type const& normal) {
		return this_type::DB_range() * normal + this_type::DB_min();
	}
	static scalar_type DB_normalize(scalar_type const& divert) {
		return (divert - this_type::DB_min()) /this_type::DB_range();
	}

	static scalar_type DR_diverse(scalar_type const& normal) {
		return this_type::DR_range() * normal + this_type::DR_min();
	}
	static scalar_type DR_normalize(scalar_type const& divert) {
		return (divert - this_type::DR_min()) /this_type::DR_range();
	}
};

}
}

namespace color {

template< typename type_name >
using YDbDr = ::color::model< typename ::color::category::YDbDr< type_name > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct luma< ::color::category::YDbDr< tag_name > > {
public:
	typedef ::color::category::YDbDr< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::YDbDr<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::YDbDr<tag_name> > const& color_parameter) {
	typedef ::color::category::YDbDr< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::gray<category_type>::akin_type akin_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<0,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::YDbDr<tag_name> >::akin_type >::return_type
red(::color::model< ::color::category::YDbDr<tag_name> > const& color_parameter) {
	typedef ::color::category::YDbDr< tag_name > category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	return ::color::model< akin_type >(color_parameter).template get<red_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::YDbDr<tag_name> >::akin_type >::return_type
green(::color::model< ::color::category::YDbDr<tag_name> > const& color_parameter) {
	typedef ::color::category::YDbDr<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	return ::color::model< akin_type >(color_parameter).template get<green_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::YDbDr<tag_name> >::akin_type >::return_type
blue(::color::model< ::color::category::YDbDr<tag_name> > const& color_parameter) {
	typedef ::color::category::YDbDr<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	return ::color::model< akin_type >(color_parameter).template get<blue_p>();
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::YDbDr< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YDbDr< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YDbDr< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	::color::model< akin_type > rgb_instance(color_parameter);
	rgb_instance.template set<blue_p > (component_parameter);
	color_parameter = rgb_instance;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::YDbDr< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YDbDr< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YDbDr< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::YDbDr< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YDbDr< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YDbDr< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<red_p> (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::YDbDr< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::YDbDr< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YDbDr< tag_name > category_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef double scalar_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	color_parameter.template set<0>(reformat_type::template process<0,0>(component_parameter));
}

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename gray_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type g = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		auto Y = diverse_type::template process<0>(g);
		static auto const Db = diverse_type::template process<1>(0.5);
		static auto const Dr = diverse_type::template process<2>(0.5);
		container_left_trait_type::template set<0>(left, Y);
		container_left_trait_type::template set<1>(left, Db);
		container_left_trait_type::template set<2>(left, Dr);
	}
};

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::YDbDr< category_left_type > YDbDr_const_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type const Wr = YDbDr_const_type::Wr();
		static scalar_type const Wb = YDbDr_const_type::Wb();
		static scalar_type const Wg = YDbDr_const_type::Wg();
		static scalar_type const Umax = YDbDr_const_type::Umax();
		static scalar_type const Vmax = YDbDr_const_type::Vmax();
		scalar_type r = scalar_type(1) - normalize_type::template process< cyan_p>(container_right_trait_type::template get< cyan_p>(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<magenta_p>(container_right_trait_type::template get<magenta_p>(right));
		scalar_type b = scalar_type(1) - normalize_type::template process< yellow_p>(container_right_trait_type::template get< yellow_p>(right));
		scalar_type Y = Wr * r + Wg * g + Wb * b;
		scalar_type u = Umax * (b - Y)/(1- Wb);
		scalar_type v = Vmax * (r - Y)/(1- Wr);
		scalar_type Db = YDbDr_const_type::DB_scale() * u;
		scalar_type Dr = YDbDr_const_type::DR_scale() * v;
		Db = YDbDr_const_type::DB_normalize(Db);
		Dr = YDbDr_const_type::DR_normalize(Dr);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(Y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(Db));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(Dr));
	}
};

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::cmyk< cmyk_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_left_type;
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmyk_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;
	typedef ::color::model< cmyk_category_type > cmyk_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YDbDr_model_type(rgb_model_type(cmyk_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::hsl< hsl_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsl_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;
	typedef ::color::model< hsl_category_type > hsl_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YDbDr_model_type(rgb_model_type(hsl_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;
	typedef ::color::model< hsv_category_type > hsv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YDbDr_model_type(rgb_model_type(hsv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename hsi_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::hsi< hsi_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_left_type;
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsi_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;
	typedef ::color::model< hsi_category_type > hsi_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YDbDr_model_type(rgb_model_type(hsi_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename rgb_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::YDbDr< category_left_type > YDbDr_const_type;

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type const Wr = YDbDr_const_type::Wr();
		static scalar_type const Wb = YDbDr_const_type::Wb();
		static scalar_type const Wg = YDbDr_const_type::Wg();
		static scalar_type const Umax = YDbDr_const_type::Umax();
		static scalar_type const Vmax = YDbDr_const_type::Vmax();
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type Y = Wr * r + Wg * g + Wb * b;
		scalar_type u = Umax * (b - Y)/(1- Wb);
		scalar_type v = Vmax * (r - Y)/(1- Wr);
		scalar_type Db = YDbDr_const_type::DB_scale() * u;
		scalar_type Dr = YDbDr_const_type::DR_scale() * v;
		Db = YDbDr_const_type::DB_normalize(Db);
		Dr = YDbDr_const_type::DR_normalize(Dr);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(Y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(Db));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(Dr));
	}
};

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename yiq_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_left_type;
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yiq_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;
	typedef ::color::model< yiq_category_type > yiq_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YDbDr_model_type(rgb_model_type(yiq_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YDbDr_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	>
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::yuv< yuv_tag_name, yuv_reference_number >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_left_type;
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yuv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;
	typedef ::color::model< yuv_category_type > yuv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YDbDr_model_type(rgb_model_type(yuv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_left_type;
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YCgCo_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;
	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YDbDr_model_type(rgb_model_type(YCgCo_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::YDbDr< tag_left_name >
	,::color::category::YDbDr< tag_right_name>
	> {
public:
	typedef ::color::category::YDbDr< tag_left_name > category_left_type;
	typedef ::color::category::YDbDr< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace akin {

template< typename category_name, ::color::constant::YPbPr::reference_enum reference_number >
struct YPbPr {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::gray_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::gray_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::gray_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::gray_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::gray_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::gray_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::gray_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmy_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 < reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmy_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 < reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmy_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 < reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmy_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 < reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmy_float , reference_number > {
	typedef ::color::category::YPbPr_float < reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmy_double , reference_number > {
	typedef ::color::category::YPbPr_double < reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmy_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble< reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmyk_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmyk_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmyk_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmyk_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmyk_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmyk_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::cmyk_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsl_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsl_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsl_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsl_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsl_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsl_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsl_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsv_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsv_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsv_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsv_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsv_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsv_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsv_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsi_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsi_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsi_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsi_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsi_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsi_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::hsi_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::rgb_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::rgb_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::rgb_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::rgb_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::rgb_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::rgb_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::rgb_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::yiq_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::yiq_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::yiq_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::yiq_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::yiq_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::yiq_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::yiq_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YCgCo_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YCgCo_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YCgCo_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YCgCo_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YCgCo_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YCgCo_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YCgCo_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YDbDr_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YDbDr_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YDbDr_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YDbDr_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YDbDr_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YDbDr_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::YDbDr_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace akin {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
struct YPbPr< ::color::category::YPbPr< tag_name, reference_number >, reference_number > {
public:
	typedef ::color::category::YPbPr< tag_name, reference_number > akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::xyz_uint8 , reference_number > {
	typedef ::color::category::YPbPr_uint8 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::xyz_uint16 , reference_number > {
	typedef ::color::category::YPbPr_uint16 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::xyz_uint32 , reference_number > {
	typedef ::color::category::YPbPr_uint32 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::xyz_uint64 , reference_number > {
	typedef ::color::category::YPbPr_uint64 <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::xyz_float , reference_number > {
	typedef ::color::category::YPbPr_float <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::xyz_double , reference_number > {
	typedef ::color::category::YPbPr_double <reference_number> akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct YPbPr< ::color::category::xyz_ldouble, reference_number > {
	typedef ::color::category::YPbPr_ldouble<reference_number> akin_type;
};

}
}

namespace color {
namespace trait {

template < ::color::constant::YPbPr::reference_enum reference_number > struct info< ::color::category::YPbPr_uint8 <reference_number> > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::YPbPr::reference_enum reference_number > struct info< ::color::category::YPbPr_uint16 <reference_number> > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::YPbPr::reference_enum reference_number > struct info< ::color::category::YPbPr_uint32 <reference_number> > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::YPbPr::reference_enum reference_number > struct info< ::color::category::YPbPr_uint64 <reference_number> > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::YPbPr::reference_enum reference_number > struct info< ::color::category::YPbPr_float <reference_number> > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::YPbPr::reference_enum reference_number > struct info< ::color::category::YPbPr_double <reference_number> > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template < ::color::constant::YPbPr::reference_enum reference_number > struct info< ::color::category::YPbPr_ldouble<reference_number> > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct YPbPr_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 1, 0.5, 0.5 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 1, 0.5, 0.5 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, -0.5, -0.5 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, -0.5, -0.5 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 1, 1, 1 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 1, 1, 1 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< ::color::constant::YPbPr::reference_enum reference_number >
struct bound< ::color::category::YPbPr_float< reference_number > >
	: public ::color::_internal::utility::bound::YPbPr_scalar< unsigned, float > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct bound< ::color::category::YPbPr_double<reference_number> >
	: public ::color::_internal::utility::bound::YPbPr_scalar< unsigned, double > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct bound< ::color::category::YPbPr_ldouble<reference_number> >
	: public ::color::_internal::utility::bound::YPbPr_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::YPbPr::reference_enum reference_number >
struct bound< ::color::category::YPbPr_uint16<reference_number> >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct bound< ::color::category::YPbPr_uint32<reference_number> >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct bound< ::color::category::YPbPr_uint64<reference_number> >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct bound< ::color::category::YPbPr_uint8<reference_number> >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::YPbPr::reference_enum reference_number >
struct component< ::color::category::YPbPr_float<reference_number> >
	: public ::color::_internal::utility::component::array< float, unsigned > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct component< ::color::category::YPbPr_double<reference_number> >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct component< ::color::category::YPbPr_ldouble<reference_number> >
	: public ::color::_internal::utility::component::array< long double, unsigned > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::YPbPr::reference_enum reference_number >
struct component< ::color::category::YPbPr_uint8<reference_number> >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct component< ::color::category::YPbPr_uint16<reference_number> >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct component< ::color::category::YPbPr_uint32<reference_number> >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct component< ::color::category::YPbPr_uint64<reference_number> >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::YPbPr::reference_enum reference_number >
struct container< ::color::category::YPbPr_float<reference_number> >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct container< ::color::category::YPbPr_double<reference_number> >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct container< ::color::category::YPbPr_ldouble<reference_number> >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< ::color::constant::YPbPr::reference_enum reference_number >
struct container< ::color::category::YPbPr_uint8<reference_number> >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct container< ::color::category::YPbPr_uint16<reference_number> >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct container< ::color::category::YPbPr_uint32<reference_number> >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< ::color::constant::YPbPr::reference_enum reference_number >
struct container< ::color::category::YPbPr_uint64<reference_number> >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {
namespace constant {
namespace YPbPr {

namespace _internal {
template< typename scalar_name, ::color::constant::YPbPr::reference_enum reference_number >
struct base {
	typedef scalar_name scalar_type;
	static scalar_type const CRed() {
		return 0.0;
	}
	static scalar_type const CGreen() {
		return 0.0;
	}
	static scalar_type const CBlue() {
		return 0.0;
	}

};

template< typename scalar_name >
struct base< scalar_name, ::color::constant::YPbPr::BT_601_entity > {
	typedef scalar_name scalar_type;
	typedef ::color::constant::YPbPr::_internal::base< scalar_name, ::color::constant::YPbPr::BT_601_entity > this_type, base_type;

	static scalar_type const CRed() {
		return 0.298839 ;
	}
	static scalar_type const CGreen() {
		return 1 - base_type::CRed() - base_type::CBlue();
	}
	static scalar_type const CBlue() {
		return 0.114350 ;
	}
};

template< typename scalar_name >
struct base< scalar_name, ::color::constant::YPbPr::BT_709_entity > {
	typedef scalar_name scalar_type;
	typedef ::color::constant::YPbPr::_internal::base< scalar_name, ::color::constant::YPbPr::BT_709_entity > this_type, base_type;

	static scalar_type const CRed() {
		return 0.2126729;
	}
	static scalar_type const CGreen() {
		return 1 - base_type::CRed() - base_type::CBlue();
	}
	static scalar_type const CBlue() {
		return 0.0721750;
	}
};

template< typename scalar_name >
struct base< scalar_name, ::color::constant::YPbPr::BT_2020_entity > {
	typedef scalar_name scalar_type;
	typedef ::color::constant::YPbPr::_internal::base< scalar_name, ::color::constant::YPbPr::BT_2020_entity > this_type, base_type;

	static scalar_type const CRed() {
		return 0.2627;
	}
	static scalar_type const CGreen() {
		return 1 - base_type::CRed() - base_type::CBlue();
	}
	static scalar_type const CBlue() {
		return 0.0593;
	}
};
}

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
struct parameter
	: public ::color::constant::YPbPr::_internal::base< typename ::color::trait::scalar< ::color::category::YPbPr<tag_name,reference_number> >::instance_type, reference_number > {
public:
	typedef ::color::category::YPbPr<tag_name,reference_number > category_type;

	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;

	typedef ::color::constant::YPbPr::parameter<category_type,reference_number> this_type;

	static scalar_type const Pb_min() {
		return -0.5;
	}
	static scalar_type const Pb_max() {
		return 0.5;
	}
	static scalar_type const Pb_range() {
		return 1.0;
	}

	static scalar_type const Pr_min() {
		return -0.5;
	}
	static scalar_type const Pr_max() {
		return 0.5;
	}
	static scalar_type const Pr_range() {
		return 1.0;
	}

	static scalar_type const a11() {
		return 1;
	}
	static scalar_type const a12() {
		return 0;
	}
	static scalar_type const a13() {
		return 2*(1- this_type::CRed());
	}
	static scalar_type const a21() {
		return 1;
	}
	static scalar_type const a22() {
		return 2 * this_type::CBlue()*(this_type::CBlue() - 1) / this_type::CGreen();
	}
	static scalar_type const a23() {
		return 2 * this_type::CRed() *(this_type::CRed() - 1) / this_type::CGreen();
	}
	static scalar_type const a31() {
		return 1;
	}
	static scalar_type const a32() {
		return 2*(1- this_type::CBlue());
	}
	static scalar_type const a33() {
		return 0;
	}

	static scalar_type const b11() {
		return this_type::CRed();
	}
	static scalar_type const b12() {
		return this_type::CGreen();
	}
	static scalar_type const b13() {
		return this_type::CBlue();
	}
	static scalar_type const b21() {
		return - this_type::CRed()/(1- this_type::CBlue()) / 2;
	}
	static scalar_type const b22() {
		return - this_type::CGreen()/(1- this_type::CBlue()) / 2;
	}
	static scalar_type const b23() {
		return 0.5;
	}
	static scalar_type const b31() {
		return 0.5;
	}
	static scalar_type const b32() {
		return - this_type::CGreen()/(1- this_type::CRed()) / 2;
	}
	static scalar_type const b33() {
		return - this_type::CBlue()/(1- this_type::CRed()) / 2;
	}

	static scalar_type Pb_normalize(scalar_type const& divert) {
		return (divert - this_type::Pb_min()) /this_type::Pb_range();
	}
	static scalar_type Pb_diverse(scalar_type const& normal) {
		return this_type::Pb_range() * normal + this_type::Pb_min();
	}

	static scalar_type Pr_diverse(scalar_type const& normal) {
		return this_type::Pr_range() * normal + this_type::Pr_min();
	}
	static scalar_type Pr_normalize(scalar_type const& divert) {
		return (divert - this_type::Pr_min()) /this_type::Pr_range();
	}

};

}
}
}

namespace color {

template< typename type_name, ::color::constant::YPbPr::reference_enum reference_number = ::color::constant::YPbPr::BT_709_entity >
using YPbPr = ::color::model< ::color::category::YPbPr< type_name, reference_number > >;

}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
struct luma< ::color::category::YPbPr< tag_name, reference_number > > {
public:
	typedef ::color::category::YPbPr< tag_name, reference_number > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace get {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::YPbPr<tag_name,reference_number> >::akin_type >::return_type
gray(::color::model< ::color::category::YPbPr<tag_name,reference_number> > const& color_parameter) {
	typedef ::color::category::YPbPr< tag_name, reference_number > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::gray<category_type>::akin_type akin_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<0,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YPbPr<tag_name,reference_number> >::akin_type >::return_type
red(::color::model< ::color::category::YPbPr< tag_name, reference_number> > const& color_parameter) {
	typedef ::color::category::YPbPr< tag_name,reference_number > category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	return ::color::model< akin_type >(color_parameter).template get<red_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::YPbPr<tag_name,reference_number> >::akin_type >::return_type
green(::color::model< ::color::category::YPbPr<tag_name,reference_number> > const& color_parameter) {
	typedef ::color::category::YPbPr<tag_name,reference_number> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	return ::color::model< akin_type >(color_parameter).template get<green_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::YPbPr<tag_name,reference_number> >::akin_type >::return_type
blue(::color::model< ::color::category::YPbPr<tag_name,reference_number> > const& color_parameter) {
	typedef ::color::category::YPbPr<tag_name,reference_number> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	return ::color::model< akin_type >(color_parameter).template get<blue_p>();
}

}
}

namespace color {
namespace set {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
inline
void
blue
(
	::color::model< ::color::category::YPbPr<tag_name,reference_number> > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YPbPr<tag_name,reference_number> >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YPbPr<tag_name,reference_number> category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	::color::model< akin_type > rgb_instance(color_parameter);
	rgb_instance.template set<blue_p > (component_parameter);
	color_parameter = rgb_instance;
}

}
}

namespace color {
namespace set {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
inline
void
green
(
	::color::model< ::color::category::YPbPr<tag_name,reference_number> > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YPbPr<tag_name,reference_number> >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YPbPr<tag_name,reference_number> category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
inline
void
red
(
	::color::model< ::color::category::YPbPr<tag_name,reference_number> > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::YPbPr<tag_name,reference_number> >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YPbPr<tag_name,reference_number> category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<red_p> (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name, ::color::constant::YPbPr::reference_enum reference_number >
inline
void
gray
(
	::color::model< ::color::category::YPbPr<tag_name,reference_number> > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::YPbPr<tag_name,reference_number> >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::YPbPr<tag_name,reference_number> category_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef double scalar_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	color_parameter.template set<0>(reformat_type::template process<0,0>(component_parameter));
}

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename gray_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type g = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		auto Y = diverse_type::template process<0>(g);
		static auto const Pb = diverse_type::template process<1>(0.5);
		static auto const Pr = diverse_type::template process<2>(0.5);
		container_left_trait_type::template set<0>(left, Y);
		container_left_trait_type::template set<1>(left, Pb);
		container_left_trait_type::template set<2>(left, Pr);
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename cmy_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::YPbPr::parameter< YPbPr_tag_name, YPbPr_reference_number > YPbPr_parameter_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		,yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = scalar_type(1) - normalize_type::template process<cyan_p >(container_right_trait_type::template get<cyan_p >(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<magenta_p >(container_right_trait_type::template get<magenta_p >(right));
		scalar_type b = scalar_type(1) - normalize_type::template process<yellow_p >(container_right_trait_type::template get<yellow_p >(right));
		scalar_type Y = YPbPr_parameter_type::b11() * r + YPbPr_parameter_type::b12() * g + YPbPr_parameter_type::b13() * b ;
		scalar_type Pb = YPbPr_parameter_type::b21() * r + YPbPr_parameter_type::b22() * g + YPbPr_parameter_type::b23() * b ;
		scalar_type Pr = YPbPr_parameter_type::b31() * r + YPbPr_parameter_type::b32() * g + YPbPr_parameter_type::b33() * b ;
		Pb = YPbPr_parameter_type::Pb_normalize(Pb);
		Pr = YPbPr_parameter_type::Pr_normalize(Pr);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(Y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(Pb));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(Pr));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename cmyk_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::cmyk< cmyk_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_left_type;
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmyk_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;
	typedef ::color::model< cmyk_category_type > cmyk_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YPbPr_model_type(rgb_model_type(cmyk_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename hsl_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::hsl< hsl_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsl_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;
	typedef ::color::model< hsl_category_type > hsl_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YPbPr_model_type(rgb_model_type(hsl_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename hsv_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name,YPbPr_reference_number > YPbPr_category_type, category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;
	typedef ::color::model< hsv_category_type > hsv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YPbPr_model_type(rgb_model_type(hsv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename hsi_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::hsi< hsi_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name,YPbPr_reference_number > YPbPr_category_type, category_left_type;
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsi_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;
	typedef ::color::model< hsi_category_type > hsi_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YPbPr_model_type(rgb_model_type(hsi_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename rgb_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::YPbPr::parameter< YPbPr_tag_name, YPbPr_reference_number > YPbPr_parameter_type;

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type Y = YPbPr_parameter_type::b11() * r + YPbPr_parameter_type::b12() * g + YPbPr_parameter_type::b13() * b;
		scalar_type Pb = YPbPr_parameter_type::b21() * r + YPbPr_parameter_type::b22() * g + YPbPr_parameter_type::b23() * b;
		scalar_type Pr = YPbPr_parameter_type::b31() * r + YPbPr_parameter_type::b32() * g + YPbPr_parameter_type::b33() * b;
		Pb = YPbPr_parameter_type::Pb_normalize(Pb);
		Pr = YPbPr_parameter_type::Pr_normalize(Pr);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(Y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(Pb));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(Pr));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename yiq_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_left_type;
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yiq_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;
	typedef ::color::model< yiq_category_type > yiq_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YPbPr_model_type(rgb_model_type(yiq_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::yuv< yuv_tag_name, yuv_reference_number >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_left_type;
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yuv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;
	typedef ::color::model< yuv_category_type > yuv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YPbPr_model_type(rgb_model_type(yuv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename YCgCo_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_left_type;
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YCgCo_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;
	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YPbPr_model_type(rgb_model_type(YCgCo_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename YDbDr_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_left_type;
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;
	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YPbPr_model_type(rgb_model_type(YDbDr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename tag_left_name, ::color::constant::YPbPr::reference_enum reference_left_number
	,typename tag_right_name, ::color::constant::YPbPr::reference_enum reference_right_number
	>
struct convert
	<
	::color::category::YPbPr< tag_left_name, reference_left_number >
	,::color::category::YPbPr< tag_right_name, reference_right_number >
	> {
public:
	typedef ::color::category::YPbPr< tag_left_name , reference_left_number > category_left_type;
	typedef ::color::category::YPbPr< tag_right_name, reference_right_number > category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::gray_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::gray_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::gray_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::gray_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::gray_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::gray_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::gray_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::cmy_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::cmy_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::cmy_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::cmy_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::cmy_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::cmy_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::cmy_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::cmyk_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::cmyk_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::cmyk_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::cmyk_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::cmyk_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::cmyk_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::cmyk_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::hsl_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::hsl_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::hsl_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::hsl_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::hsl_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::hsl_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::hsl_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::hsv_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::hsv_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::hsv_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::hsv_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::hsv_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::hsv_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::hsv_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::hsi_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::hsi_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::hsi_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::hsi_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::hsi_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::hsi_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::hsi_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::rgb_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::rgb_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::rgb_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::rgb_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::rgb_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::rgb_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::rgb_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::yiq_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::yiq_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::yiq_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::yiq_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::yiq_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::yiq_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::yiq_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::yuv::reference_enum reference_number >struct xyz< ::color::category::yuv_uint8 <reference_number> > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct xyz< ::color::category::yuv_uint16 <reference_number> > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct xyz< ::color::category::yuv_uint32 <reference_number> > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct xyz< ::color::category::yuv_uint64 <reference_number> > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct xyz< ::color::category::yuv_float <reference_number> > {
	typedef ::color::category::xyz_float akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct xyz< ::color::category::yuv_double <reference_number> > {
	typedef ::color::category::xyz_double akin_type;
};
template< ::color::constant::yuv::reference_enum reference_number >struct xyz< ::color::category::yuv_ldouble<reference_number> > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::YCgCo_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::YCgCo_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::YCgCo_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::YCgCo_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::YCgCo_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::YCgCo_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::YCgCo_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct xyz< ::color::category::YDbDr_uint8 > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< >struct xyz< ::color::category::YDbDr_uint16 > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< >struct xyz< ::color::category::YDbDr_uint32 > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< >struct xyz< ::color::category::YDbDr_uint64 > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< >struct xyz< ::color::category::YDbDr_float > {
	typedef ::color::category::xyz_float akin_type;
};
template< >struct xyz< ::color::category::YDbDr_double > {
	typedef ::color::category::xyz_double akin_type;
};
template< >struct xyz< ::color::category::YDbDr_ldouble > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< ::color::constant::YPbPr::reference_enum reference_number >struct xyz< ::color::category::YPbPr_uint8 <reference_number> > {
	typedef ::color::category::xyz_uint8 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct xyz< ::color::category::YPbPr_uint16 <reference_number> > {
	typedef ::color::category::xyz_uint16 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct xyz< ::color::category::YPbPr_uint32 <reference_number> > {
	typedef ::color::category::xyz_uint32 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct xyz< ::color::category::YPbPr_uint64 <reference_number> > {
	typedef ::color::category::xyz_uint64 akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct xyz< ::color::category::YPbPr_float <reference_number> > {
	typedef ::color::category::xyz_float akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct xyz< ::color::category::YPbPr_double <reference_number> > {
	typedef ::color::category::xyz_double akin_type;
};
template< ::color::constant::YPbPr::reference_enum reference_number >struct xyz< ::color::category::YPbPr_ldouble<reference_number> > {
	typedef ::color::category::xyz_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template <> struct info< ::color::category::xyz_uint8 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::xyz_uint16 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::xyz_uint32 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::xyz_uint64 > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::xyz_float > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::xyz_double > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};
template <> struct info< ::color::category::xyz_ldouble > {
public:
	enum { implemented_entity = true };
	enum { meaningful_entity = true };
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct xyz_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 100, 100, 100 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 100, 100, 100 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 100, 100, 100 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 100, 100, 100 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::xyz_float >
	: public ::color::_internal::utility::bound::xyz_scalar< unsigned, float > {
};

template< >
struct bound< ::color::category::xyz_double >
	: public ::color::_internal::utility::bound::xyz_scalar< unsigned, double > {
};

template< >
struct bound< ::color::category::xyz_ldouble >
	: public ::color::_internal::utility::bound::xyz_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::xyz_uint8 >
	: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

template< >
struct bound< ::color::category::xyz_uint16 >
	: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

template< >
struct bound< ::color::category::xyz_uint32 >
	: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

template< >
struct bound< ::color::category::xyz_uint64 >
	: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::xyz_float >
	: public ::color::_internal::utility::component::array< float, unsigned> {
};

template< >
struct component< ::color::category::xyz_double >
	: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct component< ::color::category::xyz_ldouble >
	: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::xyz_uint8 >
	: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

template< >
struct component< ::color::category::xyz_uint16 >
	: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

template< >
struct component< ::color::category::xyz_uint32 >
	: public ::color::_internal::utility::component::array< std::uint32_t, unsigned > {
};

template< >
struct component< ::color::category::xyz_uint64 >
	: public ::color::_internal::utility::component::array< std::uint64_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::xyz_float >
	: public ::color::_internal::utility::container::array< float, 3 > {
};

template< >
struct container< ::color::category::xyz_double >
	: public ::color::_internal::utility::container::array< double, 3 > {
};

template< >
struct container< ::color::category::xyz_ldouble >
	: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::xyz_uint8 >
	: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

template< >
struct container< ::color::category::xyz_uint16 >
	: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

template< >
struct container< ::color::category::xyz_uint32 >
	: public ::color::_internal::utility::container::array< std::uint32_t, 3 > {
};

template< >
struct container< ::color::category::xyz_uint64 >
	: public ::color::_internal::utility::container::array< std::uint64_t, 3 > {
};

}
}

namespace color {

template< typename type_name >
using xyz = ::color::model< typename ::color::category::xyz< type_name > >;

}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::xyz< tag_name> >::component_const_type
inphase(::color::model< ::color::category::xyz< tag_name> > const& color_parameter) {
	typedef ::color::category::xyz< tag_name> category_type;
	enum { inphase_p = ::color::place::_internal::inphase<category_type>::position_enum };
	return color_parameter.template get<inphase_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::model< ::color::category::xyz< tag_name> >::component_const_type
quadrature(::color::model< ::color::category::xyz< tag_name> > const& color_parameter) {
	typedef ::color::category::xyz< tag_name> category_type;
	enum { quadrature_p = ::color::place::_internal::quadrature<category_type>::position_enum };
	return color_parameter.template get<quadrature_p>();
}

}
}

namespace color {
namespace constant {
namespace xyz {
namespace illuminant {

enum observer_enum { two_entity, ten_entity };
enum name_enum {
	A_entity,
	B_entity,
	C_entity,
	D50_entity,
	D55_entity,
	D65_entity,
	D75_entity,
	E_entity,
	F1_entity,
	F2_entity,
	F3_entity,
	F4_entity,
	F5_entity,
	F6_entity,
	F7_entity,
	F8_entity,
	F9_entity,
	F10_entity,
	F11_entity,
	F12_entity
};

namespace _intrnal {

template
<
	typename scalar_name
	,::color::constant::xyz::illuminant::name_enum name_number
	,::color::constant::xyz::illuminant::observer_enum observer_number
	>
struct base {
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::A_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.44757);
	} static scalar_type y() {
		return scalar_type(0.40745);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::B_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.34842);
	} static scalar_type y() {
		return scalar_type(0.35161);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::C_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.310063);
	} static scalar_type y() {
		return scalar_type(0.316158);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::D50_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.34567);
	} static scalar_type y() {
		return scalar_type(0.35850);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::D55_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.33242);
	} static scalar_type y() {
		return scalar_type(0.34743);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::D65_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.312713);
	} static scalar_type y() {
		return scalar_type(0.329016);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::D75_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.29902);
	} static scalar_type y() {
		return scalar_type(0.31485);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::E_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.33333);
	} static scalar_type y() {
		return scalar_type(0.33333);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F1_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.31310);
	} static scalar_type y() {
		return scalar_type(0.33727);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F2_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.37208);
	} static scalar_type y() {
		return scalar_type(0.37529);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F3_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.40910);
	} static scalar_type y() {
		return scalar_type(0.39430);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F4_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.44018);
	} static scalar_type y() {
		return scalar_type(0.40329);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F5_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.31379);
	} static scalar_type y() {
		return scalar_type(0.34531);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F6_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.37790);
	} static scalar_type y() {
		return scalar_type(0.38835);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F7_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.31292);
	} static scalar_type y() {
		return scalar_type(0.32933);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F8_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.34588);
	} static scalar_type y() {
		return scalar_type(0.35875);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F9_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.37417);
	} static scalar_type y() {
		return scalar_type(0.37281);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F10_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.34609);
	} static scalar_type y() {
		return scalar_type(0.35986);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F11_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.38052);
	} static scalar_type y() {
		return scalar_type(0.37713);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F12_entity, ::color::constant::xyz::illuminant::two_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.43695);
	} static scalar_type y() {
		return scalar_type(0.40441);
	}
};

template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::A_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.45117);
	} static scalar_type y() {
		return scalar_type(0.40594);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::B_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.34980);
	} static scalar_type y() {
		return scalar_type(0.35270);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::C_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.31039);
	} static scalar_type y() {
		return scalar_type(0.31905);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::D50_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.34773);
	} static scalar_type y() {
		return scalar_type(0.35952);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::D55_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.33411);
	} static scalar_type y() {
		return scalar_type(0.34877);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::D65_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.31382);
	} static scalar_type y() {
		return scalar_type(0.33100);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::D75_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.29968);
	} static scalar_type y() {
		return scalar_type(0.31740);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::E_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.33333);
	} static scalar_type y() {
		return scalar_type(0.33333);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F1_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.31811);
	} static scalar_type y() {
		return scalar_type(0.33559);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F2_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.37925);
	} static scalar_type y() {
		return scalar_type(0.36733);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F3_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.41761);
	} static scalar_type y() {
		return scalar_type(0.38324);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F4_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.44920);
	} static scalar_type y() {
		return scalar_type(0.39074);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F5_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.31975);
	} static scalar_type y() {
		return scalar_type(0.34246);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F6_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.38660);
	} static scalar_type y() {
		return scalar_type(0.37847);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F7_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.31569);
	} static scalar_type y() {
		return scalar_type(0.32960);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F8_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.34902);
	} static scalar_type y() {
		return scalar_type(0.35939);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F9_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.37829);
	} static scalar_type y() {
		return scalar_type(0.37045);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F10_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.35090);
	} static scalar_type y() {
		return scalar_type(0.35444);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F11_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.38541);
	} static scalar_type y() {
		return scalar_type(0.37123);
	}
};
template< typename scalar_name > struct base< scalar_name, ::color::constant::xyz::illuminant::F12_entity, ::color::constant::xyz::illuminant::ten_entity > {
	typedef scalar_name scalar_type;
	static scalar_type x() {
		return scalar_type(0.44256);
	} static scalar_type y() {
		return scalar_type(0.39717);
	}
};

}

template< typename scalar_name,::color::constant::xyz::illuminant::name_enum name_number, ::color::constant::xyz::illuminant::observer_enum observer_number >
struct point
	: private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, name_number, observer_number > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, name_number, observer_number > base_type;

public:
	static scalar_type const X() {
		return base_type::x()/base_type::y();
	}
	static scalar_type const Y() {
		return scalar_type(1);
	}
	static scalar_type const Z() {
		return (scalar_type(1)-base_type::x()-base_type::y())/base_type::y();
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::A_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::A_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::A_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(1.09850);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.35585);
	}
};

template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::C_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::C_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::C_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.98074);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(1.18232);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::D50_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::D50_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::D50_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.96422);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.82521);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::D55_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::D55_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::D55_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.95682);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.92149);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::D65_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::D65_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::D65_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.95047);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(1.08883);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::D75_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::D75_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::D75_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.94972);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(1.22638);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::E_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::E_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::E_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(1.00000);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(1.00000);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::F2_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::F2_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::F2_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.99186);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.67393);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::F7_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::F7_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::F7_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.95041);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(1.08747);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::F11_entity, ::color::constant::xyz::illuminant::two_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::F11_entity, ::color::constant::xyz::illuminant::two_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::F11_entity, ::color::constant::xyz::illuminant::two_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(1.00962);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.64350);
	}
};

template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::A_entity, ::color::constant::xyz::illuminant::ten_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::A_entity, ::color::constant::xyz::illuminant::ten_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::A_entity, ::color::constant::xyz::illuminant::ten_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(1.11144);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.35200);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::C_entity, ::color::constant::xyz::illuminant::ten_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::C_entity, ::color::constant::xyz::illuminant::ten_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::C_entity, ::color::constant::xyz::illuminant::ten_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.97285);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(1.16145);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::D50_entity, ::color::constant::xyz::illuminant::ten_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::D50_entity, ::color::constant::xyz::illuminant::ten_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::D50_entity, ::color::constant::xyz::illuminant::ten_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.96720);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.81427);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::D55_entity, ::color::constant::xyz::illuminant::ten_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::D55_entity, ::color::constant::xyz::illuminant::ten_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::D55_entity, ::color::constant::xyz::illuminant::ten_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.95799);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.90926);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::D65_entity, ::color::constant::xyz::illuminant::ten_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::D65_entity, ::color::constant::xyz::illuminant::ten_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::D65_entity, ::color::constant::xyz::illuminant::ten_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.94811);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(1.07304);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::D75_entity, ::color::constant::xyz::illuminant::ten_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::D75_entity, ::color::constant::xyz::illuminant::ten_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::D75_entity, ::color::constant::xyz::illuminant::ten_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.94416);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(1.20641);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::F2_entity, ::color::constant::xyz::illuminant::ten_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::F2_entity, ::color::constant::xyz::illuminant::ten_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::F2_entity, ::color::constant::xyz::illuminant::ten_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(1.03279);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.69027);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::F7_entity, ::color::constant::xyz::illuminant::ten_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::F7_entity, ::color::constant::xyz::illuminant::ten_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::F7_entity, ::color::constant::xyz::illuminant::ten_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(0.95792);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(1.07687);
	}
};
template< typename scalar_name > struct point< scalar_name, ::color::constant::xyz::illuminant::F11_entity, ::color::constant::xyz::illuminant::ten_entity > : private ::color::constant::xyz::illuminant::_intrnal::base<scalar_name, ::color::constant::xyz::illuminant::F11_entity, ::color::constant::xyz::illuminant::ten_entity > {
private:
	typedef scalar_name scalar_type;
	typedef ::color::constant::xyz::illuminant::_intrnal::base< scalar_name, ::color::constant::xyz::illuminant::F11_entity, ::color::constant::xyz::illuminant::ten_entity > base_type;
public:
	static scalar_type const X() {
		return scalar_type(1.03863);
	} static scalar_type const Y() {
		return scalar_type(1);
	} static scalar_type const Z() {
		return scalar_type(0.65607);
	}
};

}
}
}
}

namespace color {
namespace constant {
namespace xyz {
namespace space {

enum name_enum {
	none_entity,
	LabGamut_entity,
	Adobe_entity,
	Apple_entity,
	Best_entity,
	Beta_entity,
	Bruce_entity,
	CIE_entity,
	ColorMatch_entity,
	Don_entity,
	ECI_entity,
	Ekta_Space_PS5_entity,
	NTSC_entity,
	PAL_SECAM_entity,
	ProPhoto_entity,
	SMPTE_C_entity,
	sRGB_entity,
	WideGamut_entity,
	BT2020_entity,
};

template< typename scalar_name, ::color::constant::xyz::space::name_enum name_number >
struct primary {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = name_number };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{};
		return value;
	}
	static coord_type const& green() {
		static coord_type value{};
		return value;
	}
	static coord_type const& blue() {
		static coord_type value{};
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::Adobe_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::Adobe_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6400, 0.3300 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2100, 0.7100 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1500, 0.0600 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::Apple_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::Apple_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6250, 0.3400 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2800, 0.5950 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1550, 0.0700 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::Best_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::Best_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.7347, 0.2653 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2150, 0.7750 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1300, 0.0350 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::Beta_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::Beta_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6888, 0.3112 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.1986, 0.7551 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1265, 0.0352 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::Bruce_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::Bruce_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6400, 0.3300 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2800, 0.6500 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1500, 0.0600 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::CIE_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::CIE_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.7350, 0.2650 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2740, 0.7170 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1670, 0.0090 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::ColorMatch_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::ColorMatch_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6300, 0.3400 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2950, 0.6050 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1500, 0.0750 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::Don_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::Don_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6960, 0.3000 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2150, 0.7650 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1300, 0.0350 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::ECI_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::ECI_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6700, 0.3300 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2100, 0.7100 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1400, 0.0800 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::Ekta_Space_PS5_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::Ekta_Space_PS5_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6950, 0.3050 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2600, 0.7000 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1100, 0.0050 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::NTSC_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::NTSC_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6700, 0.3300 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2100, 0.7100 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1400, 0.0800 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::PAL_SECAM_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::PAL_SECAM_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6400, 0.3300 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.2900, 0.6000 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1500, 0.0600 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::ProPhoto_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::ProPhoto_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.7347, 0.2653 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.1596, 0.8404 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.0366, 0.0001 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::SMPTE_C_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::SMPTE_C_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6300, 0.3400 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.3100, 0.5950 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1550, 0.0700 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::sRGB_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::sRGB_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.6400, 0.3300 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.3000, 0.6000 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1500, 0.0600 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::WideGamut_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::WideGamut_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.7350, 0.2650 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.1150, 0.8260 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1570, 0.0180 };
		return value;
	}
};
template< typename scalar_name > struct primary< scalar_name, ::color::constant::xyz::space::BT2020_entity > {
public:
	typedef scalar_name scalar_type;
	enum { name_entity = ::color::constant::xyz::space::BT2020_entity };
private:
	typedef std::array<scalar_type,2> coord_type;
public:
	static coord_type const& red() {
		static coord_type value{ 0.7080, 0.2920 };
		return value;
	} static coord_type const& green() {
		static coord_type value{ 0.1700, 0.7970 };
		return value;
	} static coord_type const& blue() {
		static coord_type value{ 0.1310, 0.0460 };
		return value;
	}
};

template< typename scalar_name, ::color::constant::xyz::space::name_enum name_number = ::color::constant::xyz::space::none_entity >
struct gamma {
	typedef scalar_name scalar_type;

	static scalar_type encode(scalar_type const& value) {
		return value ;
	}

	static scalar_type decode(scalar_type const& value) {
		return value;
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::ECI_entity > {
	typedef scalar_name scalar_type;
	static scalar_type s() {
		return pow((1+0.16)/ 3, 3) * pow((3 -1) / 0.16, 3 -1);
	} static scalar_type t() {
		return 0.16/(3 -1);
	} static scalar_type encode(scalar_type const& value) {
		if(value < t()/s()) {
			return s() * value;
		}
		return (1 + 0.16) * pow(value, scalar_type(1) / scalar_type(3)) - 0.16;
	} static scalar_type decode(scalar_type const& value) {
		if(value < t()) {
			return value / s();
		}
		return pow((value + 0.16) / (1 + 0.16), 3);
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::sRGB_entity > {
	typedef scalar_name scalar_type;
	static scalar_type s() {
		return pow((1+0.055)/ 2.4, 2.4) * pow((2.4 -1) / 0.055, 2.4 -1);
	} static scalar_type t() {
		return 0.055/(2.4 -1);
	} static scalar_type encode(scalar_type const& value) {
		if(value < t()/s()) {
			return s() * value;
		}
		return (1 + 0.055) * pow(value, scalar_type(1) / scalar_type(2.4)) - 0.055;
	} static scalar_type decode(scalar_type const& value) {
		if(value < t()) {
			return value / s();
		}
		return pow((value + 0.055) / (1 + 0.055), 2.4);
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::Adobe_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.19921875));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.19921875));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::Apple_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(1.8));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(1.8));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::Best_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::Beta_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::Bruce_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::CIE_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::ColorMatch_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(1.8));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(1.8));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::Don_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};

template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::Ekta_Space_PS5_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::NTSC_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::PAL_SECAM_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::ProPhoto_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(1.8));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(1.8));
	}
};
template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::SMPTE_C_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};

template< typename scalar_name > struct gamma< scalar_name, ::color::constant::xyz::space::WideGamut_entity > {
	typedef scalar_name scalar_type;
	static scalar_type encode(scalar_type const& value) {
		return pow(value, scalar_type(1) / scalar_type(2.2));
	} static scalar_type decode(scalar_type const& value) {
		return pow(value, scalar_type(2.2));
	}
};

template< ::color::constant::xyz::space::name_enum name_number >
struct illuminant {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;

	static name_type name() {
		return ::color::constant::xyz::illuminant::D65_entity;
	}
	static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity ;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::LabGamut_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D65_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D65_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::Adobe_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D65_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D65_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::Apple_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D65_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D65_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::Best_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D50_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D50_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::Beta_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D50_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D50_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::Bruce_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D65_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D65_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::CIE_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::E_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::E_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::ColorMatch_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D50_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D50_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::Don_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D50_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D50_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::ECI_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D50_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D50_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::Ekta_Space_PS5_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D50_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D50_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::NTSC_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::C_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::C_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::PAL_SECAM_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D65_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D65_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::ProPhoto_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D50_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D50_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::SMPTE_C_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D65_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D65_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::sRGB_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D65_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D65_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::WideGamut_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D50_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D50_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};
template<> struct illuminant< ::color::constant::xyz::space::BT2020_entity> {
	typedef ::color::constant::xyz::illuminant::name_enum name_type;
	typedef ::color::constant::xyz::illuminant::observer_enum observer_type;
	enum { name_entity = ::color::constant::xyz::illuminant::D65_entity };
	enum { observer_entity = ::color::constant::xyz::illuminant::two_entity };
	static name_type name() {
		return ::color::constant::xyz::illuminant::D65_entity;
	} static observer_type observer() {
		return ::color::constant::xyz::illuminant::two_entity;
	}
};

}
}
}
}

namespace color {
namespace constant {
namespace xyz {
namespace adaptation {

enum scaling_enum {
	XYZ_entity
	,Bradford_entity
	,VonKries_entity
};

template
<
	typename scalar_name
	,::color::constant::xyz::adaptation::scaling_enum scaling_number = ::color::constant::xyz::adaptation::XYZ_entity
	>
struct method {
	typedef scalar_name scalar_type;

	static scalar_type const a11() {
		return 1;
	}
	static scalar_type const a12() {
		return 0;
	}
	static scalar_type const a13() {
		return 0;
	}

	static scalar_type const a21() {
		return 0;
	}
	static scalar_type const a22() {
		return 1;
	}
	static scalar_type const a23() {
		return 0;
	}

	static scalar_type const a31() {
		return 0;
	}
	static scalar_type const a32() {
		return 0;
	}
	static scalar_type const a33() {
		return 1;
	}

	static scalar_type const i11() {
		return 1;
	}
	static scalar_type const i12() {
		return 0;
	}
	static scalar_type const i13() {
		return 0;
	}

	static scalar_type const i21() {
		return 0;
	}
	static scalar_type const i22() {
		return 1;
	}
	static scalar_type const i23() {
		return 0;
	}

	static scalar_type const i31() {
		return 0;
	}
	static scalar_type const i32() {
		return 0;
	}
	static scalar_type const i33() {
		return 1;
	}
};
template < typename scalar_name > struct method< scalar_name, ::color::constant::xyz::adaptation::XYZ_entity > {
	typedef scalar_name scalar_type;
	static scalar_type const a11() {
		return 1;
	} static scalar_type const a12() {
		return 0;
	} static scalar_type const a13() {
		return 0;
	} static scalar_type const a21() {
		return 0;
	} static scalar_type const a22() {
		return 1;
	} static scalar_type const a23() {
		return 0;
	} static scalar_type const a31() {
		return 0;
	} static scalar_type const a32() {
		return 0;
	} static scalar_type const a33() {
		return 1;
	} static scalar_type const i11() {
		return 1;
	} static scalar_type const i12() {
		return 0;
	} static scalar_type const i13() {
		return 0;
	} static scalar_type const i21() {
		return 0;
	} static scalar_type const i22() {
		return 1;
	} static scalar_type const i23() {
		return 0;
	} static scalar_type const i31() {
		return 0;
	} static scalar_type const i32() {
		return 0;
	} static scalar_type const i33() {
		return 1;
	}
}

;

template < typename scalar_name > struct method< scalar_name, ::color::constant::xyz::adaptation::Bradford_entity > {
	typedef scalar_name scalar_type;
	static scalar_type const a11() {
		return 0.8951000;
	} static scalar_type const a12() {
		return 0.2664000;
	} static scalar_type const a13() {
		return -0.1614000;
	} static scalar_type const a21() {
		return -0.7502000;
	} static scalar_type const a22() {
		return 1.7135000;
	} static scalar_type const a23() {
		return 0.0367000;
	} static scalar_type const a31() {
		return 0.0389000;
	} static scalar_type const a32() {
		return -0.0685000;
	} static scalar_type const a33() {
		return 1.0296000;
	} static scalar_type const i11() {
		return 0.9869929;
	} static scalar_type const i12() {
		return -0.1470543;
	} static scalar_type const i13() {
		return 0.1599627;
	} static scalar_type const i21() {
		return 0.4323053;
	} static scalar_type const i22() {
		return 0.5183603;
	} static scalar_type const i23() {
		return 0.0492912;
	} static scalar_type const i31() {
		return -0.0085287;
	} static scalar_type const i32() {
		return 0.0400428;
	} static scalar_type const i33() {
		return 0.9684867;
	}
}

;

template < typename scalar_name > struct method< scalar_name, ::color::constant::xyz::adaptation::VonKries_entity > {
	typedef scalar_name scalar_type;
	static scalar_type const a11() {
		return 0.4002400;
	} static scalar_type const a12() {
		return 0.7076000;
	} static scalar_type const a13() {
		return -0.0808100;
	} static scalar_type const a21() {
		return -0.2263000;
	} static scalar_type const a22() {
		return 1.1653200;
	} static scalar_type const a23() {
		return 0.0457000;
	} static scalar_type const a31() {
		return 0.0000000;
	} static scalar_type const a32() {
		return 0.0000000;
	} static scalar_type const a33() {
		return 0.9182200;
	} static scalar_type const i11() {
		return 1.8599364;
	} static scalar_type const i12() {
		return -1.1293816;
	} static scalar_type const i13() {
		return 0.2198974;
	} static scalar_type const i21() {
		return 0.3611914;
	} static scalar_type const i22() {
		return 0.6388125;
	} static scalar_type const i23() {
		return -0.0000064;
	} static scalar_type const i31() {
		return 0.0000000;
	} static scalar_type const i32() {
		return 0.0000000;
	} static scalar_type const i33() {
		return 1.0890636;
	}
}

;

template
<
	typename scalar_name
	,::color::constant::xyz::illuminant::name_enum left_number = ::color::constant::xyz::illuminant::D50_entity
	,::color::constant::xyz::illuminant::name_enum right_number = ::color::constant::xyz::illuminant::D65_entity
	,::color::constant::xyz::adaptation::scaling_enum scaling_number = ::color::constant::xyz::adaptation::XYZ_entity
	>
struct matrix {
	typedef scalar_name scalar_type;
	typedef method<scalar_type,scaling_number > method_type;

	typedef ::color::constant::xyz::illuminant::point< scalar_name, left_number, ::color::constant::xyz::illuminant::two_entity > source_type;
	typedef ::color::constant::xyz::illuminant::point< scalar_name, right_number, ::color::constant::xyz::illuminant::two_entity > destination_type;

	static scalar_type rho_S() {
		return method_type::a11() * source_type::X() + method_type::a12() * source_type::Y() + method_type::a13() * source_type::Z();
	}
	static scalar_type gamma_S() {
		return method_type::a21() * source_type::X() + method_type::a22() * source_type::Y() + method_type::a23() * source_type::Z();
	}
	static scalar_type beta_S() {
		return method_type::a31() * source_type::X() + method_type::a32() * source_type::Y() + method_type::a33() * source_type::Z();
	}

	static scalar_type rho_D() {
		return method_type::a11() * destination_type::X() + method_type::a12() * destination_type::Y() + method_type::a13() * destination_type::Z();
	}
	static scalar_type gamma_D() {
		return method_type::a21() * destination_type::X() + method_type::a22() * destination_type::Y() + method_type::a23() * destination_type::Z();
	}
	static scalar_type beta_D() {
		return method_type::a31() * destination_type::X() + method_type::a32() * destination_type::Y() + method_type::a33() * destination_type::Z();
	}

	static scalar_type rho_R() {
		return rho_D() / rho_S();
	}
	static scalar_type gamma_R() {
		return gamma_D() / gamma_S();
	}
	static scalar_type beta_R() {
		return beta_D() / beta_S();
	}

	static scalar_type const a11() {
		return method_type::a11()*method_type::i11()*rho_R() + method_type::a21()*method_type::i12()*gamma_R() + method_type::a31()*method_type::i13()*beta_R();
	}
	static scalar_type const a12() {
		return method_type::a12()*method_type::i11()*rho_R() + method_type::a22()*method_type::i12()*gamma_R() + method_type::a32()*method_type::i13()*beta_R();
	}
	static scalar_type const a13() {
		return method_type::a13()*method_type::i11()*rho_R() + method_type::a23()*method_type::i12()*gamma_R() + method_type::a33()*method_type::i13()*beta_R();
	}
	static scalar_type const a21() {
		return method_type::a11()*method_type::i21()*rho_R() + method_type::a21()*method_type::i22()*gamma_R() + method_type::a31()*method_type::i23()*beta_R();
	}
	static scalar_type const a22() {
		return method_type::a12()*method_type::i21()*rho_R() + method_type::a22()*method_type::i22()*gamma_R() + method_type::a32()*method_type::i23()*beta_R();
	}
	static scalar_type const a23() {
		return method_type::a13()*method_type::i21()*rho_R() + method_type::a23()*method_type::i22()*gamma_R() + method_type::a33()*method_type::i23()*beta_R();
	}
	static scalar_type const a31() {
		return method_type::a11()*method_type::i31()*rho_R() + method_type::a21()*method_type::i32()*gamma_R() + method_type::a31()*method_type::i33()*beta_R();
	}
	static scalar_type const a32() {
		return method_type::a12()*method_type::i31()*rho_R() + method_type::a22()*method_type::i32()*gamma_R() + method_type::a32()*method_type::i33()*beta_R();
	}
	static scalar_type const a33() {
		return method_type::a13()*method_type::i31()*rho_R() + method_type::a23()*method_type::i32()*gamma_R() + method_type::a33()*method_type::i33()*beta_R();
	}

	static scalar_type const i11() {
		return method_type::a11()*method_type::i11()/rho_R() + method_type::a21()*method_type::i12()/gamma_R() + method_type::a31()*method_type::i13()/beta_R();
	}
	static scalar_type const i12() {
		return method_type::a12()*method_type::i11()/rho_R() + method_type::a22()*method_type::i12()/gamma_R() + method_type::a32()*method_type::i13()/beta_R();
	}
	static scalar_type const i13() {
		return method_type::a13()*method_type::i11()/rho_R() + method_type::a23()*method_type::i12()/gamma_R() + method_type::a33()*method_type::i13()/beta_R();
	}
	static scalar_type const i21() {
		return method_type::a11()*method_type::i21()/rho_R() + method_type::a21()*method_type::i22()/gamma_R() + method_type::a31()*method_type::i23()/beta_R();
	}
	static scalar_type const i22() {
		return method_type::a12()*method_type::i21()/rho_R() + method_type::a22()*method_type::i22()/gamma_R() + method_type::a32()*method_type::i23()/beta_R();
	}
	static scalar_type const i23() {
		return method_type::a13()*method_type::i21()/rho_R() + method_type::a23()*method_type::i22()/gamma_R() + method_type::a33()*method_type::i23()/beta_R();
	}
	static scalar_type const i31() {
		return method_type::a11()*method_type::i31()/rho_R() + method_type::a21()*method_type::i32()/gamma_R() + method_type::a31()*method_type::i33()/beta_R();
	}
	static scalar_type const i32() {
		return method_type::a12()*method_type::i31()/rho_R() + method_type::a22()*method_type::i32()/gamma_R() + method_type::a32()*method_type::i33()/beta_R();
	}
	static scalar_type const i33() {
		return method_type::a13()*method_type::i31()/rho_R() + method_type::a23()*method_type::i32()/gamma_R() + method_type::a33()*method_type::i33()/beta_R();
	}

	static void encode(scalar_name &X, scalar_name &Y, scalar_name &Z) {
		scalar_type x = a11() * X + a12() * Y + a13() * Z;
		scalar_type y = a21() * X + a22() * Y + a23() * Z;
		scalar_type z = a31() * X + a32() * Y + a33() * Z;
		X = x;
		Y = y;
		Z = z;
	}

	static void decode(scalar_name &X, scalar_name &Y, scalar_name &Z) {
		scalar_type x = i11() * X + i12() * Y + i13() * Z;
		scalar_type y = i21() * X + i22() * Y + i23() * Z;
		scalar_type z = i31() * X + i32() * Y + i33() * Z;
		X = x;
		Y = y;
		Z = z;
	}

};

template
<
	typename scalar_name
	,::color::constant::xyz::illuminant::name_enum both_number
	,::color::constant::xyz::adaptation::scaling_enum scaling_number
	>
struct matrix< scalar_name, both_number, both_number, scaling_number > {
	typedef scalar_name scalar_type;

	static void encode(scalar_name &X, scalar_name &Y, scalar_name &Z) {
	}
	static void decode(scalar_name &X, scalar_name &Y, scalar_name &Z) {
	}
};

}
}
}
}

namespace color {
namespace constant {
namespace xyz {
namespace transformation {

template
<
	typename category_name
	, ::color::constant::xyz::space::name_enum space_number = ::color::constant::xyz::space::sRGB_entity
	, ::color::constant::xyz::illuminant::name_enum illuminant_number = static_cast< color::constant::xyz::illuminant::name_enum >(::color::constant::xyz::space::illuminant< space_number >::name_entity)
	, ::color::constant::xyz::illuminant::observer_enum observer_number = static_cast< color::constant::xyz::illuminant::observer_enum >(::color::constant::xyz::space::illuminant< space_number >::observer_entity)
	>
struct matrix {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::xyz::transformation::matrix<category_type> this_type;

	typedef ::color::constant::xyz::space::primary< scalar_type, space_number > system_type;

	typedef ::color::constant::xyz::illuminant::point< scalar_type, illuminant_number, observer_number > wp_type;

	static scalar_type const xr() {
		return system_type::red()[0];
	}
	static scalar_type const yr() {
		return system_type::red()[1];
	}
	static scalar_type const xg() {
		return system_type::green()[0];
	}
	static scalar_type const yg() {
		return system_type::green()[1];
	}
	static scalar_type const xb() {
		return system_type::blue()[0];
	}
	static scalar_type const yb() {
		return system_type::blue()[1];
	}

private:
	static scalar_type const detQ() {
		return -yr()*yg()*yb()/((xg()-xb())*yr() + (xb()-xr())*yg() + (xr()-xg())*yb()) ;
	}
	static scalar_type const Q11() {
		return -detQ() * ((xb()-1)*yg() + (1-xg())*yb())/(yb()* yg());
	}
	static scalar_type const Q12() {
		return -detQ() * ((yg()-1)*xb() + (1-yb())*xg())/(yb()* yg());
	}
	static scalar_type const Q13() {
		return -detQ() * (xb()*yg() - xg()*yb()) / (yb()*yg());
	}

	static scalar_type const Q21() {
		return detQ() * ((xb()-1)*yr() + (1-xr())*yb())/(yb()* yr());
	}
	static scalar_type const Q22() {
		return detQ() * ((yr()-1)*xb() + (1-yb())*xr())/(yb()* yr());
	}
	static scalar_type const Q23() {
		return detQ() * (xb()*yr() - xr()*yb()) / (yb()*yr());
	}

	static scalar_type const Q31() {
		return -detQ() * ((xg()-1)*yr() + (1-xr())*yg())/(yg()* yr());
	}
	static scalar_type const Q32() {
		return -detQ() * ((yr()-1)*xg() + (1-yg())*xr())/(yg()* yr());
	}
	static scalar_type const Q33() {
		return -detQ() * (xg()*yr() - xr()*yg()) / (yg()*yr());
	}

public:
	static scalar_type const Sr() {
		return Q11() * wp_type::X() + Q12() * wp_type::Y() + Q13() * wp_type::Z();
	}
	static scalar_type const Sg() {
		return Q21() * wp_type::X() + Q22() * wp_type::Y() + Q23() * wp_type::Z();
	}
	static scalar_type const Sb() {
		return Q31() * wp_type::X() + Q32() * wp_type::Y() + Q33() * wp_type::Z();
	}

	static scalar_type const Xr() {
		return xr()/yr() ;
	}
	static scalar_type const Yr() {
		return scalar_type(1);
	}
	static scalar_type const Zr() {
		return (scalar_type(1)-xr()-yr())/yr();
	}

	static scalar_type const Xg() {
		return xg()/yg();
	}
	static scalar_type const Yg() {
		return scalar_type(1);
	}
	static scalar_type const Zg() {
		return (scalar_type(1)-xg()-yg())/yg();
	}

	static scalar_type const Xb() {
		return xb()/yb();
	}
	static scalar_type const Yb() {
		return scalar_type(1);
	}
	static scalar_type const Zb() {
		return (scalar_type(1)-xb()-yb())/yb();
	}

	static scalar_type const M11() {
		return Sr()*Xr();
	}
	static scalar_type const M12() {
		return Sg()*Xg();
	}
	static scalar_type const M13() {
		return Sb()*Xb();
	}
	static scalar_type const M21() {
		return Sr()*Yr();
	}
	static scalar_type const M22() {
		return Sg()*Yg();
	}
	static scalar_type const M23() {
		return Sb()*Yb();
	}
	static scalar_type const M31() {
		return Sr()*Zr();
	}
	static scalar_type const M32() {
		return Sg()*Zg();
	}
	static scalar_type const M33() {
		return Sb()*Zb();
	}

	static scalar_type const detM() {
		return M11()*(M22()*M33()-M23()*M32())-M12()*(M21()*M33()-M23()*M31())+M13()*(M21()*M32()-M22()*M31());
	}

	static scalar_type const i11() {
		return (M22()*M33()-M23()*M32()) / detM();
	}
	static scalar_type const i12() {
		return (M13()*M32()-M12()*M33()) / detM();
	}
	static scalar_type const i13() {
		return (M12()*M23()-M13()*M22()) / detM();
	}
	static scalar_type const i21() {
		return (M23()*M31()-M21()*M33()) / detM();
	}
	static scalar_type const i22() {
		return (M11()*M33()-M13()*M31()) / detM();
	}
	static scalar_type const i23() {
		return (M13()*M21()-M11()*M23()) / detM();
	}
	static scalar_type const i31() {
		return (M21()*M32()-M22()*M31()) / detM();
	}
	static scalar_type const i32() {
		return (M12()*M31()-M11()*M32()) / detM();
	}
	static scalar_type const i33() {
		return (M11()*M22()-M12()*M21()) / detM();
	}
};
}
}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::xyz<tag_name> >::akin_type >::return_type
red(::color::model< ::color::category::xyz<tag_name> > const& color_parameter) {
	typedef ::color::category::xyz<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::xyz::transformation::matrix< category_type > xyz_matrix_type;
	typedef ::color::constant::xyz::space::gamma< scalar_type, ::color::constant::xyz::space::sRGB_entity > xyz_gamma_type;
	enum {
		red_p = ::color::place::_internal::red<akin_type>::position_enum
	};
	static const scalar_type i11 = xyz_matrix_type::i11(), i12 = xyz_matrix_type::i12(), i13 = xyz_matrix_type::i13();
	scalar_type x = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type y = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type z = normalize_type::template process<2>(color_parameter.template get<2>());
	scalar_type r = i11 * x + i12 * y + i13 * z;
	r = xyz_gamma_type::encode(r);
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::xyz<tag_name> >::akin_type >::return_type
green(::color::model< ::color::category::xyz<tag_name> > const& color_parameter) {
	typedef ::color::category::xyz<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::xyz::transformation::matrix< category_type > xyz_matrix_type;
	typedef ::color::constant::xyz::space::gamma< scalar_type, ::color::constant::xyz::space::sRGB_entity > xyz_gamma_type;
	enum {
		green_p = ::color::place::_internal::green<akin_type>::position_enum
	};
	static const scalar_type i21 = xyz_matrix_type::i21(), i22 = xyz_matrix_type::i22(), i23 = xyz_matrix_type::i23();
	scalar_type x = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type y = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type z = normalize_type::template process<2>(color_parameter.template get<2>());
	scalar_type g = i21 * x + i22 * y + i23 * z;
	g = xyz_gamma_type::encode(g);
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::xyz<tag_name> >::akin_type >::return_type
blue(::color::model< ::color::category::xyz<tag_name> > const& color_parameter) {
	typedef ::color::category::xyz<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::xyz::transformation::matrix< category_type > xyz_matrix_type;
	typedef ::color::constant::xyz::space::gamma< scalar_type, ::color::constant::xyz::space::sRGB_entity > xyz_gamma_type;
	enum {
		blue_p = ::color::place::_internal::blue<akin_type>::position_enum
	};
	static const scalar_type i31 = xyz_matrix_type::i31(), i32 = xyz_matrix_type::i32(), i33 = xyz_matrix_type::i33();
	scalar_type x = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type y = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type z = normalize_type::template process<2>(color_parameter.template get<2>());
	scalar_type b = i31 * x + i32 * y + i33 * z;
	b = xyz_gamma_type::encode(b);
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::xyz<tag_name> >::akin_type >::return_type
gray(::color::model< ::color::category::xyz<tag_name> > const& color_parameter) {
	typedef ::color::category::xyz< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type > ::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<0,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::model< ::color::category::xyz< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::xyz< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::xyz< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< red_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::model< ::color::category::xyz< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::xyz< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::xyz< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set< green_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::model< ::color::category::xyz< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::xyz< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::xyz< tag_name > category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	::color::model< akin_type > rgb(color_parameter);
	rgb.template set<blue_p > (component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::xyz< tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::xyz< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::xyz< tag_name > category_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef double scalar_type;
	typedef ::color::_internal::reformat< category_type, akin_type, scalar_type > reformat_type;
	enum {
		luma_p = ::color::place::_internal::luma<category_type>::position_enum
	};
	color_parameter.template set<luma_p>(reformat_type::template process<luma_p,0>(component_parameter));
}

}
}

namespace color {
namespace _internal {

template
<
	typename xyz_tag_name
	,typename gray_tag_name
	>
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::constant::xyz::transformation::matrix< category_left_type > xyz_matrix_type;
	typedef ::color::constant::xyz::space::gamma< scalar_type, ::color::constant::xyz::space::sRGB_entity > xyz_gamma_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static const scalar_type b2 = xyz_matrix_type::M21() + xyz_matrix_type::M22() + xyz_matrix_type::M23();
		static const scalar_type b1 = (xyz_matrix_type::M11() + xyz_matrix_type::M12() + xyz_matrix_type::M13()) / b2;
		static const scalar_type b3 = (xyz_matrix_type::M31() + xyz_matrix_type::M32() + xyz_matrix_type::M33()) / b2;
		scalar_type g = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type x = b1 * g;
		scalar_type y = g;
		scalar_type z = b3 * g;
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(x));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(y));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(z));
	}
};

}
}

namespace color {
namespace _internal {

template< typename xyz_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > cmy_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmy_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< cmy_category_type > cmy_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(cmy_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename xyz_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::cmyk< cmyk_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_right_type;

	typedef typename ::color::akin::rgb< cmyk_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< cmyk_category_type > cmyk_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(cmyk_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename xyz_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::hsl< hsl_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsl_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< hsl_category_type > hsl_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(hsl_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename xyz_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< hsv_category_type > hsv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(hsv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename xyz_tag_name, typename hsi_tag_name >
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::hsi< hsi_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsi_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< hsi_category_type > hsi_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(hsi_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename xyz_tag_name
	,typename rgb_tag_name
	>
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::constant::xyz::transformation::matrix< category_left_type > xyz_matrix_type;
	typedef ::color::constant::xyz::space::gamma< scalar_type, ::color::constant::xyz::space::sRGB_entity > xyz_gamma_type;
	typedef ::color::constant::xyz::adaptation::matrix< scalar_type > xyz_adaptation_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static const scalar_type b11 = xyz_matrix_type::M11(), b12 = xyz_matrix_type::M12(), b13 = xyz_matrix_type::M13();
		static const scalar_type b21 = xyz_matrix_type::M21(), b22 = xyz_matrix_type::M22(), b23 = xyz_matrix_type::M23();
		static const scalar_type b31 = xyz_matrix_type::M31(), b32 = xyz_matrix_type::M32(), b33 = xyz_matrix_type::M33();
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		r = xyz_gamma_type::decode(r);
		g = xyz_gamma_type::decode(g);
		b = xyz_gamma_type::decode(b);
		scalar_type x = b11 * r + b12 * g + b13 * b;
		scalar_type y = b21 * r + b22 * g + b23 * b;
		scalar_type z = b31 * r + b32 * g + b33 * b;
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(x));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(y));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(z));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename xyz_tag_name
	,typename yiq_tag_name
	>
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yiq_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< yiq_category_type > yiq_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(yiq_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename xyz_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum reference_number
	>
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::yuv< yuv_tag_name, reference_number >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::yuv< yuv_tag_name, reference_number > yuv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yuv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< yuv_category_type > yuv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(yuv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename xyz_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YCgCo_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(YCgCo_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename xyz_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(YDbDr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename xyz_tag_name
	,typename YPbPr_tag_name ,::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::xyz< xyz_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_left_type;
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YPbPr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< xyz_category_type > xyz_model_type;
	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = xyz_model_type(rgb_model_type(YPbPr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::xyz< tag_left_name >
	,::color::category::xyz< tag_right_name>
	> {
public:
	typedef ::color::category::xyz< tag_left_name > category_left_type;
	typedef ::color::category::xyz< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		ll_p = ::color::place::_internal::luma<category_left_type>::position_enum
		,il_p = ::color::place::_internal::inphase<category_left_type>::position_enum
		,ql_p = ::color::place::_internal::quadrature<category_left_type>::position_enum
	};

	enum {
		lr_p = ::color::place::_internal::luma<category_right_type>::position_enum
		,ir_p = ::color::place::_internal::inphase<category_right_type>::position_enum
		,qr_p = ::color::place::_internal::quadrature<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<ll_p>(left, reformat_type::template process<ll_p,lr_p>(container_right_trait_type::template get<lr_p>(right)));
		container_left_trait_type::template set<il_p>(left, reformat_type::template process<il_p,ir_p>(container_right_trait_type::template get<ir_p>(right)));
		container_left_trait_type::template set<ql_p>(left, reformat_type::template process<ql_p,qr_p>(container_right_trait_type::template get<qr_p>(right)));
	}
};
}
}

namespace color {
namespace _internal {

template
<
	typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	,typename xyz_tag_name
	>
struct convert
	<
	::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YPbPr_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YDbDr_tag_name
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_left_type;
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YPbPr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;
	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YDbDr_model_type(rgb_model_type(YPbPr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YDbDr_tag_name, typename xyz_tag_name >
struct convert
	<
	::color::category::YDbDr< YDbDr_tag_name >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YDbDr_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_left_type;
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;
	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YCgCo_model_type(rgb_model_type(YDbDr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename YCgCo_tag_name
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_left_type;
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YPbPr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;
	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YCgCo_model_type(rgb_model_type(YPbPr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename YCgCo_tag_name, typename xyz_tag_name >
struct convert
	<
	::color::category::YCgCo< YCgCo_tag_name >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = YCgCo_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	,typename YCgCo_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_left_type;
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YCgCo_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yuv_category_type > yuv_model_type;
	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yuv_model_type(rgb_model_type(YCgCo_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	,typename YDbDr_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_left_type;
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yuv_category_type > yuv_model_type;
	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yuv_model_type(rgb_model_type(YDbDr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_left_type;
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YPbPr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yuv_category_type > yuv_model_type;
	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yuv_model_type(rgb_model_type(YPbPr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	,typename xyz_tag_name
	>
struct convert
	<
	::color::category::yuv< yuv_tag_name, yuv_reference_number >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::yuv< yuv_tag_name, yuv_reference_number > yuv_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yuv_category_type > yuv_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yuv_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yiq_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum reference_number
	>
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::yuv< yuv_tag_name, reference_number >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_left_type;
	typedef ::color::category::yuv< yuv_tag_name, reference_number > yuv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yuv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yiq_category_type > yiq_model_type;
	typedef ::color::model< yuv_category_type > yuv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yiq_model_type(rgb_model_type(yuv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_left_type;
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YCgCo_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yiq_category_type > yiq_model_type;
	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yiq_model_type(rgb_model_type(YCgCo_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_left_type;
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yiq_category_type > yiq_model_type;
	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yiq_model_type(rgb_model_type(YDbDr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename yiq_tag_name
	,typename YPbPr_tag_name
	,::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_left_type;
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YPbPr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yiq_category_type > yiq_model_type;
	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yiq_model_type(rgb_model_type(YPbPr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename xyz_tag_name >
struct convert
	<
	::color::category::yiq< yiq_tag_name >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< yiq_category_type > yiq_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = yiq_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename yiq_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yiq_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< yiq_category_type > yiq_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(yiq_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename hsi_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum reference_number
	>
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::yuv< yuv_tag_name, reference_number >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::yuv< yuv_tag_name, reference_number > yuv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yuv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< yuv_category_type > yuv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(yuv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YCgCo_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(YCgCo_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(YDbDr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename hsi_tag_name
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YPbPr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(YPbPr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsi_tag_name, typename xyz_tag_name >
struct convert
	<
	::color::category::hsi< hsi_tag_name >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsi_category_type > hsi_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsi_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename hsv_tag_name
	,typename hsi_right_name
	>
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::hsi< hsi_right_name>
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_left_type;
	typedef ::color::category::hsi< hsi_right_name> hsi_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsi_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsv_category_type > hsv_model_type;
	typedef ::color::model< hsi_category_type > hsi_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsv_model_type(rgb_model_type(hsi_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename rgb_tag_name >
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar<category_left_type> scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		, value_p = ::color::place::_internal::value<category_left_type>::position_enum
	};

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		, blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type lo = std::min<scalar_type>({r,g,b});
		scalar_type v = std::max<scalar_type>({r,g,b});
		scalar_type delta = v - lo;
		scalar_type h = 0;
		scalar_type s = 0;
		if((false == scalar_trait_type::is_small(v))
		   && (false == scalar_trait_type::is_small(delta))) {
			s = delta / v;
			if(v == r) {
				h = (scalar_type(60)/scalar_type(360)) * (g - b) / delta + (g < b ? scalar_type(1) : scalar_type(0));
			}
			if(v == g) {
				h = (scalar_type(60)/scalar_type(360)) * (b - r) / delta + (scalar_type(120)/scalar_type(360));
			}
			if(v == b) {
				h = (scalar_type(60)/scalar_type(360)) * (r - g) / delta + (scalar_type(240)/scalar_type(360));
			}
		}
		container_left_trait_type::template set< hue_p>(left, diverse_type::template process< hue_p>(h));
		container_left_trait_type::template set<saturation_p>(left, diverse_type::template process<saturation_p>(s));
		container_left_trait_type::template set< value_p>(left, diverse_type::template process< value_p>(v));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename yiq_tag_name >
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_left_type;
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yiq_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsv_category_type > hsv_model_type;
	typedef ::color::model< yiq_category_type > yiq_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsv_model_type(rgb_model_type(yiq_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename hsv_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum reference_number
	>
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::yuv< yuv_tag_name, reference_number >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_left_type;
	typedef ::color::category::yuv< yuv_tag_name, reference_number > yuv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yuv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsv_category_type > hsv_model_type;
	typedef ::color::model< yuv_category_type > yuv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsv_model_type(rgb_model_type(yuv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_left_type;
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YCgCo_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsv_category_type > hsv_model_type;
	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsv_model_type(rgb_model_type(YCgCo_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_left_type;
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsv_category_type > hsv_model_type;
	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsv_model_type(rgb_model_type(YDbDr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename hsv_tag_name
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_left_type;
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YPbPr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsv_category_type > hsv_model_type;
	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsv_model_type(rgb_model_type(YPbPr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename xyz_tag_name >
struct convert
	<
	::color::category::hsv< hsv_tag_name >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsv_category_type > hsv_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsv_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > category_right_type;

	typedef double scalar_type;
	typedef ::color::trait::scalar<category_left_type> scalar_left_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type ss = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type v = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type l = v * (2-ss) / 2;
		scalar_type s = 0 ;
		{
			s = v*ss/(1- fabs(2 * l - 1));
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(h));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(s));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(l));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename hsl_tag_name
	,typename hsi_tag_name
	>
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::hsi< hsi_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_left_type;
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsi_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsl_category_type > hsl_model_type;
	typedef ::color::model< hsi_category_type > hsi_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsl_model_type(rgb_model_type(hsi_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename rgb_tag_name >
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar<category_left_type> scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		hue_p = ::color::place::_internal::hue<category_left_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_left_type>::position_enum
		, lightness_p = ::color::place::_internal::lightness<category_left_type>::position_enum
	};

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		const scalar_type hi = std::max<scalar_type>({ r, g, b });
		const scalar_type lo = std::min<scalar_type>({ r, g, b });
		scalar_type delta = hi - lo;
		scalar_type h = 0;
		scalar_type s = 0;
		scalar_type l = (hi + lo) / scalar_type(2);
		if(false == scalar_trait_type::is_small(delta)) {
			s = delta / (1 - fabs(2*l - 1));
			if(hi == r) {
				h = (scalar_type(60)/scalar_type(360)) * (g - b) / delta + (g < b ? scalar_type(1) : scalar_type(0));
			}
			if(hi == g) {
				h = (scalar_type(60)/scalar_type(360)) * (b - r) / delta + (scalar_type(120)/scalar_type(360));
			}
			if(hi == b) {
				h = (scalar_type(60)/scalar_type(360)) * (r - g) / delta + (scalar_type(240)/scalar_type(360));
			}
		}
		container_left_trait_type::template set< hue_p>(left, diverse_type::template process< hue_p>(h));
		container_left_trait_type::template set<saturation_p>(left, diverse_type::template process<saturation_p>(s));
		container_left_trait_type::template set< lightness_p>(left, diverse_type::template process< lightness_p>(l));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename yiq_tag_name >
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_left_type;
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yiq_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsl_category_type > hsl_model_type;
	typedef ::color::model< yiq_category_type > yiq_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsl_model_type(rgb_model_type(yiq_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename hsl_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum reference_number
	>
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::yuv< yuv_tag_name, reference_number >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_left_type;
	typedef ::color::category::yuv< yuv_tag_name, reference_number > yuv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yuv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsl_category_type > hsl_model_type;
	typedef ::color::model< yuv_category_type > yuv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsl_model_type(rgb_model_type(yuv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_left_type;
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YCgCo_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsl_category_type > hsl_model_type;
	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsl_model_type(rgb_model_type(YCgCo_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_left_type;
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsl_category_type > hsl_model_type;
	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsl_model_type(rgb_model_type(YDbDr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename hsl_tag_name
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_left_type;
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YPbPr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsl_category_type > hsl_model_type;
	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsl_model_type(rgb_model_type(YPbPr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename xyz_tag_name >
struct convert
	<
	::color::category::hsl< hsl_tag_name >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< hsl_category_type > hsl_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = hsl_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::hsl<hsl_tag_name>
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::hsl<hsl_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::_internal::convert< category_left_type, category_right_type > this_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	enum {
		hue_p = ::color::place::_internal::hue<category_right_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_right_type>::position_enum
		,lightness_p = ::color::place::_internal::lightness<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<hue_p >(container_right_trait_type::template get<hue_p >(right));
		scalar_type s = normalize_type::template process<saturation_p>(container_right_trait_type::template get<saturation_p>(right));
		scalar_type l = normalize_type::template process<lightness_p >(container_right_trait_type::template get<lightness_p >(right));
		scalar_type r;
		scalar_type g;
		scalar_type b;
		if(s == 0) {
			r = l;
			g = l;
			b = l;
		} else {
			scalar_type q = l < scalar_type(0.5) ? (l * (1 + s)) : (l + s - l * s);
			scalar_type p = scalar_type(2) * l - q;
			r = this_type::value(p, q, h + (scalar_type(1) / scalar_type(3)) + (scalar_type(2) / scalar_type(3) < h ? -1 :0));
			g = this_type::value(p, q, h);
			b = this_type::value(p, q, h - (scalar_type(1) / scalar_type(3)) + (h < scalar_type(1) / scalar_type(3) ? +1 :0));
		}
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}

private:
	static scalar_type value(scalar_type const& p, scalar_type const& q, scalar_type const& t) {
		if(t < scalar_type(1)/scalar_type(6)) {
			return (p + (q - p) * scalar_type(6) * t);
		}
		if(t < scalar_type(1)/scalar_type(2)) {
			return (q);
		}
		if(t < scalar_type(2)/scalar_type(3)) {
			return (p + (q - p) * ((scalar_type(2)/scalar_type(3)) - t) * scalar_type(6));
		}
		return p ;
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	enum {
		hue_p = ::color::place::_internal::hue<category_right_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_right_type>::position_enum
		,value_p = ::color::place::_internal::value<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<hue_p >(container_right_trait_type::template get<hue_p >(right));
		scalar_type s = normalize_type::template process<saturation_p>(container_right_trait_type::template get<saturation_p>(right));
		scalar_type v = normalize_type::template process<value_p >(container_right_trait_type::template get<value_p >(right));
		int region = int(6 * h);
		scalar_type f = h * 6 - region ;
		scalar_type p = v * (1 - s);
		scalar_type q = v * (1 - f * s);
		scalar_type t = v * (1 - (1 - f) * s);
		scalar_type r;
		scalar_type g;
		scalar_type b;
		switch(region % 6) {
		case 0:
			r = v, g = t, b = p;
			break;
		case 1:
			r = q, g = v, b = p;
			break;
		case 2:
			r = p, g = v, b = t;
			break;
		case 3:
			r = p, g = q, b = v;
			break;
		case 4:
			r = t, g = p, b = v;
			break;
		case 5:
			r = v, g = p, b = q;
			break;
		}
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename hsi_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::hsi< hsi_tag_name >
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::hsi< hsi_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::hsi< category_right_type > hsi_constant_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	enum {
		hue_p = ::color::place::_internal::hue<category_right_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_right_type>::position_enum
		,intensity_p = ::color::place::_internal::intensity<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<hue_p >(container_right_trait_type::template get<hue_p >(right));
		scalar_type s = normalize_type::template process<saturation_p>(container_right_trait_type::template get<saturation_p>(right));
		scalar_type i = normalize_type::template process<intensity_p >(container_right_trait_type::template get<intensity_p >(right));
		scalar_type min = i * (1 - s);
		int region = int(3 * h);
		h -= region * hsi_constant_type::third();
		h *= hsi_constant_type::two_pi();
		scalar_type n = i*(1+ s*cos(h) / cos(hsi_constant_type::deg60() - h));
		scalar_type r;
		scalar_type g;
		scalar_type b;
		switch(region % 3) {
		case 0:
			r = n;
			b = min;
			g = 3*i-(r+b);
			break;
		case 1:
			g = n;
			r = min;
			b = 3*i-(r+g);
			break;
		case 2:
			b = n;
			g = min;
			r = 3*i-(g+b);
			break;
		}
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::rgb< tag_left_name >
	,::color::category::rgb< tag_right_name>
	> {
public:
	typedef ::color::category::rgb< tag_left_name > category_left_type;
	typedef ::color::category::rgb< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			rl = ::color::place::_internal::red<category_left_type>::position_enum
			,gl = ::color::place::_internal::green<category_left_type>::position_enum
			,bl = ::color::place::_internal::blue<category_left_type>::position_enum
			,rr = ::color::place::_internal::red<category_right_type>::position_enum
			,gr = ::color::place::_internal::green<category_right_type>::position_enum
			,br = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		container_left_trait_type::template set<rl>(left, reformat_type::template process<rl,rr>(container_right_trait_type::template get<rr>(right)));
		container_left_trait_type::template set<gl>(left, reformat_type::template process<gl,gr>(container_right_trait_type::template get<gr>(right)));
		container_left_trait_type::template set<bl>(left, reformat_type::template process<bl,br>(container_right_trait_type::template get<br>(right)));
	}
};
}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename yiq_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::yiq<yiq_tag_name>
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::yiq<yiq_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::yiq< category_right_type > yiq_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	enum {
		luma_p = ::color::place::_internal::luma<category_right_type>::position_enum
		, inphase_p = ::color::place::_internal::inphase<category_right_type>::position_enum
		,quadrature_p = ::color::place::_internal::quadrature<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type a11 = yiq_const_type::a11(), a12 = yiq_const_type::a12(), a13 = yiq_const_type::a13();
		static scalar_type a21 = yiq_const_type::a21(), a22 = yiq_const_type::a22(), a23 = yiq_const_type::a23();
		static scalar_type a31 = yiq_const_type::a31(), a32 = yiq_const_type::a32(), a33 = yiq_const_type::a33();
		scalar_type y = normalize_type::template process< luma_p>(container_right_trait_type::template get< luma_p>(right));
		scalar_type i = normalize_type::template process< inphase_p>(container_right_trait_type::template get< inphase_p>(right));
		scalar_type q = normalize_type::template process<quadrature_p>(container_right_trait_type::template get<quadrature_p>(right));
		i = yiq_const_type::i_diverse(i);
		q = yiq_const_type::q_diverse(q);
		scalar_type r = a11 * y + a12 * i + a13 * q;
		scalar_type g = a21 * y + a22 * i + a23 * q;
		scalar_type b = a31 * y + a32 * i + a33 * q;
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename rgb_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	>
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::yuv< yuv_tag_name, yuv_reference_number>
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::yuv<yuv_tag_name, yuv_reference_number> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::yuv::parameter< yuv_tag_name, yuv_reference_number > yuv_parameter_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type const Wr = yuv_parameter_type::Wr();
		static scalar_type const Wb = yuv_parameter_type::Wb();
		static scalar_type const Wg = yuv_parameter_type::Wg();
		static scalar_type const Umax = yuv_parameter_type::Umax();
		static scalar_type const Vmax = yuv_parameter_type::Vmax();
		static scalar_type const b11 = 1, b12 = 0, b13 = (1 - Wr) / Vmax;
		static scalar_type const b21 = 1, b22 = - Wb*(1 - Wb) / Umax / Wg, b23 = -Wr*(1 - Wr) / Vmax / Wg;
		static scalar_type const b31 = 1, b32 = ((1 - Wb) / Umax), b33 = 0;
		scalar_type y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type u = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type v = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		u = (u - scalar_type(0.5)) * scalar_type(2) * Umax;
		v = (v - scalar_type(0.5)) * scalar_type(2) * Vmax;
		scalar_type r = y + v * b13;
		scalar_type g = y + u * b22 + v * b23;
		scalar_type b = y + u * b32;
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name>
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::YCgCo<YCgCo_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::YCgCo< category_right_type > YCgCo_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type Y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type Cg = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type Co = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		Cg = YCgCo_const_type::Cg_diverse(Cg);
		Co = YCgCo_const_type::Co_diverse(Co);
		scalar_type r = Y - Cg + Co;
		scalar_type g = Y + Cg;
		scalar_type b = Y - Cg - Co;
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name>
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::YDbDr<YDbDr_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::YDbDr< category_right_type > YDbDr_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type const Wr = YDbDr_const_type::Wr();
		static scalar_type const Wb = YDbDr_const_type::Wb();
		static scalar_type const Wg = YDbDr_const_type::Wg();
		static scalar_type const Umax = YDbDr_const_type::Umax();
		static scalar_type const Vmax = YDbDr_const_type::Vmax();
		static scalar_type const b11 = 1, b12 = 0, b13 = (1 - Wr) / Vmax;
		static scalar_type const b21 = 1, b22 = - Wb*(1 - Wb) / Umax / Wg, b23 = -Wr*(1 - Wr) / Vmax / Wg;
		static scalar_type const b31 = 1, b32 = ((1 - Wb) / Umax), b33 = 0;
		scalar_type Y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type Db = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type Dr = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type u = YDbDr_const_type::DB_diverse(Db) / YDbDr_const_type::DB_scale();
		scalar_type v = YDbDr_const_type::DR_diverse(Dr) / YDbDr_const_type::DR_scale();
		scalar_type r = Y + v * b13;
		scalar_type g = Y + u * b22 + v * b23;
		scalar_type b = Y + u * b32;
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename rgb_tag_name
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number>
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::YPbPr<YPbPr_tag_name, YPbPr_reference_number> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::YPbPr::parameter< YPbPr_tag_name, YPbPr_reference_number > YPbPr_parameter_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type Y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type Pb = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type Pr = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		Pb = YPbPr_parameter_type::Pb_diverse(Pb);
		Pr = YPbPr_parameter_type::Pr_diverse(Pr);
		scalar_type r = YPbPr_parameter_type::a11() * Y + YPbPr_parameter_type::a12() * Pb + YPbPr_parameter_type::a13() * Pr;
		scalar_type g = YPbPr_parameter_type::a21() * Y + YPbPr_parameter_type::a22() * Pb + YPbPr_parameter_type::a23() * Pr;
		scalar_type b = YPbPr_parameter_type::a31() * Y + YPbPr_parameter_type::a32() * Pb + YPbPr_parameter_type::a33() * Pr;
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename xyz_tag_name >
struct convert
	<
	::color::category::rgb< rgb_tag_name >
	,::color::category::xyz<xyz_tag_name>
	> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::xyz<xyz_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::xyz::transformation::matrix< category_right_type > xyz_matrix_type;
	typedef ::color::constant::xyz::space::gamma< scalar_type, ::color::constant::xyz::space::sRGB_entity > xyz_gamma_type;
	typedef ::color::constant::xyz::adaptation::matrix< scalar_type > xyz_adaptation_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		red_p = ::color::place::_internal::red<category_left_type>::position_enum
		,green_p = ::color::place::_internal::green<category_left_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static const scalar_type i11 = xyz_matrix_type::i11(), i12 = xyz_matrix_type::i12(), i13 = xyz_matrix_type::i13();
		static const scalar_type i21 = xyz_matrix_type::i21(), i22 = xyz_matrix_type::i22(), i23 = xyz_matrix_type::i23();
		static const scalar_type i31 = xyz_matrix_type::i31(), i32 = xyz_matrix_type::i32(), i33 = xyz_matrix_type::i33();
		scalar_type x = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type y = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type z = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type r = i11 * x + i12 * y + i13 * z;
		scalar_type g = i21 * x + i22 * y + i23 * z;
		scalar_type b = i31 * x + i32 * y + i33 * z;
		r = xyz_gamma_type::encode(r);
		g = xyz_gamma_type::encode(g);
		b = xyz_gamma_type::encode(b);
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::model< ::color::category::cmyk<tag_name > > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray< ::color::category::cmyk< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef typename ::color::akin::rgb< ::color::category::cmyk< tag_name > >::akin_type rgb_category_type;
	::color::model< rgb_category_type > rgb(color_parameter);
	::color::set::gray(rgb, component_parameter);
	color_parameter = rgb;
}

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename gray_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::gray< gray_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::operation::_internal::invert< category_right_type > invert_type;
	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
		, key_p = ::color::place::_internal::key<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set< cyan_p>(left, bound_left_trait_type::template minimum< cyan_p>());
		container_left_trait_type::template set<magenta_p>(left, bound_left_trait_type::template minimum<magenta_p>());
		container_left_trait_type::template set< yellow_p>(left, bound_left_trait_type::template minimum< yellow_p>());
		container_left_trait_type::template set< key_p>(left, reformat_type::template process<key_p,0>(invert_type::template component<0>(container_right_trait_type::template get<0>(right))));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename cmy_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::cmy< cmy_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar< category_left_type > scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		cl_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,ml_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		,yl_p = ::color::place::_internal::yellow<category_left_type>::position_enum
		,kl_p = ::color::place::_internal::key<category_left_type>::position_enum
	};

	enum {
		cr_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,mr_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		,yr_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type cc = normalize_type::template process<cr_p>(container_right_trait_type::template get<cr_p>(right));
		scalar_type cm = normalize_type::template process<mr_p>(container_right_trait_type::template get<mr_p>(right));
		scalar_type cy = normalize_type::template process<yr_p>(container_right_trait_type::template get<yr_p>(right));
		scalar_type k = std::min({ cc, cm, cy });
		scalar_type c = scalar_type(0);
		scalar_type m = scalar_type(0);
		scalar_type y = scalar_type(0);
		if(false == scalar_trait_type::is_small(1 - k)) {
			c = (cc-k) / (1-k);
			m = (cm-k) / (1-k);
			y = (cy-k) / (1-k);
		}
		container_left_trait_type::template set<cl_p>(left, diverse_type::template process<cl_p>(c));
		container_left_trait_type::template set<ml_p>(left, diverse_type::template process<ml_p>(m));
		container_left_trait_type::template set<yl_p>(left, diverse_type::template process<yl_p>(y));
		container_left_trait_type::template set<kl_p>(left, diverse_type::template process<kl_p>(k));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::cmyk< tag_left_name >
	,::color::category::cmyk< tag_right_name>
	> {
public:
	typedef ::color::category::cmyk< tag_left_name > category_left_type;
	typedef ::color::category::cmyk< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		cl_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,ml_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		,yl_p = ::color::place::_internal::yellow<category_left_type>::position_enum
		,kl_p = ::color::place::_internal::key<category_left_type>::position_enum
	};

	enum {
		cr_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,mr_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		,yr_p = ::color::place::_internal::yellow<category_right_type>::position_enum
		,kr_p = ::color::place::_internal::key<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<cr_p>(left, reformat_type::template process<cr_p,cl_p>(container_right_trait_type::template get<cl_p>(right)));
		container_left_trait_type::template set<mr_p>(left, reformat_type::template process<mr_p,ml_p>(container_right_trait_type::template get<ml_p>(right)));
		container_left_trait_type::template set<yr_p>(left, reformat_type::template process<yr_p,yl_p>(container_right_trait_type::template get<yl_p>(right)));
		container_left_trait_type::template set<kr_p>(left, reformat_type::template process<kr_p,kl_p>(container_right_trait_type::template get<kl_p>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::hsl< hsl_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > hsl_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsl_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmyk_category_type > cmyk_model_type;
	typedef ::color::model< hsl_category_type > hsl_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmyk_model_type(rgb_model_type(hsl_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::hsv< hsv_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > hsv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmyk_category_type > cmyk_model_type;
	typedef ::color::model< hsv_category_type > hsv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmyk_model_type(rgb_model_type(hsv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename hsi_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::hsi< hsi_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_left_type;
	typedef ::color::category::hsi< hsi_tag_name > hsi_category_type, category_right_type;

	typedef typename ::color::akin::rgb< hsi_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmyk_category_type > cmyk_model_type;
	typedef ::color::model< hsi_category_type > hsi_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmyk_model_type(rgb_model_type(hsi_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename rgb_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar< category_left_type > scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
		, key_p = ::color::place::_internal::key<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type k = scalar_type(1) - std::max({ r, g, b });
		scalar_type c = scalar_type(0);
		scalar_type m = scalar_type(0);
		scalar_type y = scalar_type(0);
		if(false == scalar_trait_type::is_small(1 - k)) {
			c = 1 - r / (1-k);
			m = 1 - g / (1-k);
			y = 1 - b / (1-k);
		}
		container_left_trait_type::template set< cyan_p>(left, diverse_type::template process< cyan_p>(c));
		container_left_trait_type::template set<magenta_p>(left, diverse_type::template process<magenta_p>(m));
		container_left_trait_type::template set< yellow_p>(left, diverse_type::template process< yellow_p>(y));
		container_left_trait_type::template set< key_p>(left, diverse_type::template process< key_p>(k));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename yiq_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_left_type;
	typedef ::color::category::yiq< yiq_tag_name > yiq_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yiq_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmyk_category_type > cmyk_model_type;
	typedef ::color::model< yiq_category_type > yiq_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmyk_model_type(rgb_model_type(yiq_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename cmyk_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum reference_number
	>
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::yuv< yuv_tag_name, reference_number >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_left_type;
	typedef ::color::category::yuv< yuv_tag_name, reference_number > yuv_category_type, category_right_type;

	typedef typename ::color::akin::rgb< yuv_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmyk_category_type > cmyk_model_type;
	typedef ::color::model< yuv_category_type > yuv_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmyk_model_type(rgb_model_type(yuv_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_left_type;
	typedef ::color::category::YCgCo< YCgCo_tag_name > YCgCo_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YCgCo_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmyk_category_type > cmyk_model_type;
	typedef ::color::model< YCgCo_category_type > YCgCo_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmyk_model_type(rgb_model_type(YCgCo_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_left_type;
	typedef ::color::category::YDbDr< YDbDr_tag_name > YDbDr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmyk_category_type > cmyk_model_type;
	typedef ::color::model< YDbDr_category_type > YDbDr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmyk_model_type(rgb_model_type(YDbDr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename cmyk_tag_name
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_left_type;
	typedef ::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number > YPbPr_category_type, category_right_type;

	typedef typename ::color::akin::rgb< YPbPr_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmyk_category_type > cmyk_model_type;
	typedef ::color::model< YPbPr_category_type > YPbPr_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmyk_model_type(rgb_model_type(YPbPr_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename xyz_tag_name >
struct convert
	<
	::color::category::cmyk< cmyk_tag_name >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > cmyk_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmyk_category_type > cmyk_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmyk_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::cmyk<cmyk_tag_name>
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::cmyk<cmyk_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::gray< category_left_type > gray_const_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_right_type>::position_enum
		, key_p = ::color::place::_internal::key<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type c = normalize_type::template process< cyan_p>(container_right_trait_type::template get< cyan_p>(right));
		scalar_type m = normalize_type::template process<magenta_p>(container_right_trait_type::template get<magenta_p>(right));
		scalar_type y = normalize_type::template process< yellow_p>(container_right_trait_type::template get< yellow_p>(right));
		scalar_type k = normalize_type::template process< key_p>(container_right_trait_type::template get< key_p>(right));
		scalar_type value =
			(gray_const_type::Rc() * (1-c)
			 + gray_const_type::Gc() * (1-m)
			 + gray_const_type::Bc() * (1-y)) * (1-k);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(value));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::hsl<hsl_tag_name>
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::hsl<hsl_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		lightness_p = ::color::place::_internal::lightness<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,lightness_p>(container_right_trait_type::template get<lightness_p>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::hsv<hsv_tag_name>
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::hsv<hsv_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		value_p = ::color::place::_internal::value<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,value_p>(container_right_trait_type::template get<value_p>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename hsi_tag_name >
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::hsi<hsi_tag_name>
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::hsi<hsi_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		intensity_p = ::color::place::_internal::intensity<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,intensity_p>(container_right_trait_type::template get<intensity_p>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename rgb_tag_name >
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::rgb< rgb_tag_name >
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::gray< category_left_type > gray_const_type;

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		, green_p = ::color::place::_internal::green<category_right_type>::position_enum
		, blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type value =
			gray_const_type::Rc() * normalize_type::template process<red_p > (container_right_trait_type::template get<red_p >(right))
		+ gray_const_type::Gc() * normalize_type::template process<green_p> (container_right_trait_type::template get<green_p>(right))
		+ gray_const_type::Bc() * normalize_type::template process<blue_p > (container_right_trait_type::template get<blue_p >(right));
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(value));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename yiq_tag_name >
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::yiq< yiq_tag_name >
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::yiq<yiq_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		luma_p = ::color::place::_internal::luma<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,luma_p>(container_right_trait_type::template get<luma_p>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename gray_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum reference_number
	>
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::yuv< yuv_tag_name, reference_number >
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::yuv<yuv_tag_name, reference_number> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		luma_p = ::color::place::_internal::luma<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,luma_p>(container_right_trait_type::template get<luma_p>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name >
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::YCgCo<YCgCo_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		luma_p = ::color::place::_internal::luma<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,luma_p>(container_right_trait_type::template get<luma_p>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name >
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::YDbDr<YDbDr_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		luma_p = ::color::place::_internal::luma<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,luma_p>(container_right_trait_type::template get<luma_p>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename gray_tag_name
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number >
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::YPbPr<YPbPr_tag_name, YPbPr_reference_number> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		luma_p = ::color::place::_internal::luma<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,luma_p>(container_right_trait_type::template get<luma_p>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename gray_tag_name
	,typename xyz_tag_name
	>
struct convert
	<
	::color::category::gray< gray_tag_name >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::gray< category_left_type > gray_const_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type g = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(g));
	}
};

}
}

namespace color {
namespace operation {

template
<
	typename category_name
	>
inline
typename ::color::trait::component< category_name >::component_return_type
diverse
(
	typename ::color::trait::scalar<category_name>::instance_type const& scalar
	,typename ::color::trait::index<category_name>::index_input_const_type index
) {
	return ::color::_internal::diverse< category_name >::process(scalar, index);
}

template
<
	typename category_name
	,typename ::color::trait::index< category_name >::index_instance_type index
	>
inline
typename ::color::trait::component< category_name >::component_return_type
diverse(typename ::color::trait::scalar<category_name>::instance_type const& scalar_type) {
	return ::color::_internal::diverse< category_name >::template process< index > (scalar_type);
}

}
}

namespace color {
namespace operation {

template< typename category_name >
inline
typename ::color::trait::scalar< category_name >::instance_type
normalize
(
	::color::model<category_name> const& m
	,typename ::color::trait::index<category_name>::input_const_type index
) {
	return ::color::_internal::normalize<category_name>::process(m.get(index), index) ;
}

template
<
	unsigned index_size
	,typename category_name
	>
inline
typename ::color::trait::scalar< category_name >::instance_type
normalize
(
	::color::model<category_name> const& m
) {
	return ::color::_internal::normalize<category_name>::template process<index_size>(m.template get<index_size>());
}

}
}

namespace color {
namespace operation {
namespace _internal {

template< typename category_name>
struct gamma {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::trait::scalar<category_type>::input_const_type scalar_const_input_type;

	typedef typename ::color::trait::index<category_type>::instance_type index_type;

	typedef ::color::trait::container< category_type > container_trait_type;

	typedef ::color::model<category_type> model_type;
	typedef model_type & model_input_type;
	typedef model_type const& model_const_input_type;

	typedef ::color::_internal::diverse< category_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;

	typedef ::color::operation::_internal::gamma< category_name > this_type;

	static model_type & process(model_input_type result, scalar_const_input_type scalar) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, diverse_type::process(this_type::process(normalize_type::process(result.get(index), index), scalar), index));
		}
		return result;
	}

	static model_type & process(model_input_type result, model_const_input_type left, scalar_const_input_type value) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, diverse_type::process(this_type::process(normalize_type::process(left.get(index), index), value), index));
		}
		return result;
	}

	static scalar_type process(scalar_const_input_type x, scalar_const_input_type value) {
		return std::pow(x, scalar_type(1)/value);
	}

};
}

template< typename category_name >
::color::model<category_name> &
gamma
(
	::color::model<category_name> & result
	,typename ::color::trait::scalar<category_name>::instance_type const& value
) {
	return ::color::operation::_internal::gamma<category_name>::process(result, value);
}

template< typename category_name >
::color::model<category_name> &
gamma
(
	::color::model<category_name> & result
	, ::color::model<category_name> const& right
	,typename ::color::trait::scalar<category_name>::instance_type const& value
) {
	return ::color::operation::_internal::gamma<category_name>::process(result, right, value);
}

}
}

namespace color {
namespace operation {

template< typename tag_name >
::color::model< ::color::category::gray< tag_name > > &
gamma
(
	::color::model< ::color::category::gray< tag_name > > & result
	,typename ::color::trait::scalar< ::color::category::gray< tag_name > >::instance_type const& value
) {
	typedef ::color::category::gray< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::diverse< category_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	scalar_type s = normalize_type::template process<0>(result.template get<0>());
	result.template set<0>(diverse_type::template process<0>(std::pow(s, scalar_type(1)/value)));
	return result;
}

template< typename tag_name >
::color::model< ::color::category::gray< tag_name > > &
gamma
(
	::color::model< ::color::category::gray< tag_name > > & result
	, ::color::model< ::color::category::gray< tag_name > > const& right
	,typename ::color::trait::scalar< ::color::category::gray< tag_name > >::instance_type const& value
) {
	typedef ::color::category::gray< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::diverse< category_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	scalar_type s = normalize_type::template process<0>(right.template get<0>());
	result.template set<0>(diverse_type::template process<0>(std::pow(s, scalar_type(1)/value)));
	return result;
}

inline
::color::model< ::color::category::gray_float > &
gamma
(
	::color::model< ::color::category::gray_float > & result
	,typename ::color::trait::scalar< ::color::category::gray_float >::instance_type const& value
) {
	typedef ::color::category::gray_float category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	result.set<0>(std::pow(result.get<0>(), scalar_type(1)/value));
	return result;
}

inline
::color::model< ::color::category::gray_float > &
gamma
(
	::color::model< ::color::category::gray_float > & result
	, ::color::model< ::color::category::gray_float > const& right
	,typename ::color::trait::scalar< ::color::category::gray_float >::instance_type const& value
) {
	typedef ::color::category::gray_float category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	result.set<0>(std::pow(right.get<0>(), scalar_type(1)/value));
	return result;
}

inline
::color::model< ::color::category::gray_double > &
gamma
(
	::color::model< ::color::category::gray_double > & result
	,typename ::color::trait::scalar< ::color::category::gray_double >::instance_type const& value
) {
	typedef ::color::category::gray_double category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	result.set<0>(std::pow(result.get<0>(), scalar_type(1)/value));
	return result;
}

inline
::color::model< ::color::category::gray_double > &
gamma
(
	::color::model< ::color::category::gray_double > & result
	, ::color::model< ::color::category::gray_double > const& right
	,typename ::color::trait::scalar< ::color::category::gray_double >::instance_type const& value
) {
	typedef ::color::category::gray_double category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	result.set<0>(std::pow(right.get<0>(), scalar_type(1)/value));
	return result;
}

inline
::color::model< ::color::category::gray_ldouble > &
gamma
(
	::color::model< ::color::category::gray_ldouble > & result
	,typename ::color::trait::scalar< ::color::category::gray_ldouble >::instance_type const& value
) {
	typedef ::color::category::gray_ldouble category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	result.set<0>(std::pow(result.get<0>(), scalar_type(1)/value));
	return result;
}

inline
::color::model< ::color::category::gray_ldouble > &
gamma
(
	::color::model< ::color::category::gray_ldouble > & result
	, ::color::model< ::color::category::gray_ldouble > const& right
	,typename ::color::trait::scalar< ::color::category::gray_ldouble >::instance_type const& value
) {
	typedef ::color::category::gray_ldouble category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	result.set<0>(std::pow(right.get<0>(), scalar_type(1)/value));
	return result;
}
}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename gray_tag_name >
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::gray<gray_tag_name>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::gray<gray_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::operation::_internal::invert< category_right_type > invert_type;
	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set< cyan_p>(left, reformat_type::template process< cyan_p,0>(invert_type::template component<0>(container_right_trait_type::template get<0>(right))));
		container_left_trait_type::template set<magenta_p>(left, reformat_type::template process<magenta_p,0>(invert_type::template component<0>(container_right_trait_type::template get<0>(right))));
		container_left_trait_type::template set< yellow_p>(left, reformat_type::template process< yellow_p,0>(invert_type::template component<0>(container_right_trait_type::template get<0>(right))));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
	<
	::color::category::cmy< tag_left_name >
	,::color::category::cmy< tag_right_name>
	> {
public:
	typedef ::color::category::cmy< tag_left_name > category_left_type;
	typedef ::color::category::cmy< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	enum {
		cl_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,ml_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		,yl_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	enum {
		cr_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,mr_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		,yr_p = ::color::place::_internal::yellow<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<cl_p>(left, reformat_type::template process<cl_p,cr_p>(container_right_trait_type::template get<cr_p>(right)));
		container_left_trait_type::template set<ml_p>(left, reformat_type::template process<ml_p,mr_p>(container_right_trait_type::template get<mr_p>(right)));
		container_left_trait_type::template set<yl_p>(left, reformat_type::template process<yl_p,yr_p>(container_right_trait_type::template get<yr_p>(right)));
	}
};
}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename cmyk_tag_name >
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::cmyk<cmyk_tag_name>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::cmyk<cmyk_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		cl_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,ml_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		,yl_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	enum {
		cr_p = ::color::place::_internal::cyan<category_right_type>::position_enum
		,mr_p = ::color::place::_internal::magenta<category_right_type>::position_enum
		,yr_p = ::color::place::_internal::yellow<category_right_type>::position_enum
		,kr_p = ::color::place::_internal::key<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type cc = normalize_type::template process<cr_p>(container_right_trait_type::template get<cr_p>(right));
		scalar_type cm = normalize_type::template process<mr_p>(container_right_trait_type::template get<mr_p>(right));
		scalar_type cy = normalize_type::template process<yr_p>(container_right_trait_type::template get<yr_p>(right));
		scalar_type ck = normalize_type::template process<kr_p>(container_right_trait_type::template get<kr_p>(right));
		scalar_type c = cc * (1-ck) + ck;
		scalar_type m = cm * (1-ck) + ck;
		scalar_type y = cy * (1-ck) + ck;
		container_left_trait_type::template set<cl_p>(left, diverse_type::template process<cl_p>(c));
		container_left_trait_type::template set<ml_p>(left, diverse_type::template process<ml_p>(m));
		container_left_trait_type::template set<yl_p>(left, diverse_type::template process<yl_p>(y));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename hsl_tag_name >
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::hsl<hsl_tag_name>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::hsl<hsl_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::_internal::convert< category_left_type, category_right_type > this_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	enum {
		hue_p = ::color::place::_internal::hue<category_right_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_right_type>::position_enum
		, lightness_p = ::color::place::_internal::lightness<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process< hue_p>(container_right_trait_type::template get< hue_p>(right));
		scalar_type s = normalize_type::template process<saturation_p>(container_right_trait_type::template get<saturation_p>(right));
		scalar_type l = normalize_type::template process< lightness_p>(container_right_trait_type::template get< lightness_p>(right));
		scalar_type r;
		scalar_type g;
		scalar_type b;
		if(s == 0) {
			r = l;
			g = l;
			b = l;
		} else {
			scalar_type q = l < scalar_type(0.5) ? (l * (1 + s)) : (l + s - l * s);
			scalar_type p = scalar_type(2) * l - q;
			r = this_type::value(p, q, h + (scalar_type(1) / scalar_type(3)) + (scalar_type(2) / scalar_type(3) < h ? -1 :0));
			g = this_type::value(p, q, h);
			b = this_type::value(p, q, h - (scalar_type(1) / scalar_type(3)) + (h < scalar_type(1) / scalar_type(3) ? +1 :0));
		}
		container_left_trait_type::template set< cyan_p>(left, diverse_type::template process< cyan_p>(scalar_type(1) - r));
		container_left_trait_type::template set<magenta_p>(left, diverse_type::template process<magenta_p>(scalar_type(1) - g));
		container_left_trait_type::template set< yellow_p>(left, diverse_type::template process< yellow_p>(scalar_type(1) - b));
	}

private:
	static scalar_type value(scalar_type const& p, scalar_type const& q, scalar_type const& t) {
		if(t < scalar_type(1)/scalar_type(6)) {
			return (p + (q - p) * scalar_type(6) * t);
		}
		if(t < scalar_type(1)/scalar_type(2)) {
			return (q);
		}
		if(t < scalar_type(2)/scalar_type(3)) {
			return (p + (q - p) * ((scalar_type(2)/scalar_type(3)) - t) * scalar_type(6));
		}
		return p ;
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename hsv_tag_name >
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::hsv<hsv_tag_name>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::hsv<hsv_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		,yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	enum {
		hue_p = ::color::place::_internal::hue<category_right_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_right_type>::position_enum
		,value_p = ::color::place::_internal::value<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<hue_p >(container_right_trait_type::template get<hue_p >(right));
		scalar_type s = normalize_type::template process<saturation_p>(container_right_trait_type::template get<saturation_p>(right));
		scalar_type v = normalize_type::template process<value_p >(container_right_trait_type::template get<value_p >(right));
		int region = int(6 * h);
		scalar_type f = h * 6 - region ;
		scalar_type p = v * (1 - s);
		scalar_type q = v * (1 - f * s);
		scalar_type t = v * (1 - (1 - f) * s);
		scalar_type r;
		scalar_type g;
		scalar_type b;
		switch(region % 6) {
		case 0:
			r = v, g = t, b = p;
			break;
		case 1:
			r = q, g = v, b = p;
			break;
		case 2:
			r = p, g = v, b = t;
			break;
		case 3:
			r = p, g = q, b = v;
			break;
		case 4:
			r = t, g = p, b = v;
			break;
		case 5:
			r = v, g = p, b = q;
			break;
		}
		container_left_trait_type::template set<cyan_p >(left, diverse_type::template process<cyan_p >(scalar_type(1) - r));
		container_left_trait_type::template set<magenta_p>(left, diverse_type::template process<magenta_p>(scalar_type(1) - g));
		container_left_trait_type::template set<yellow_p >(left, diverse_type::template process<yellow_p >(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename hsi_tag_name >
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::hsi<hsi_tag_name>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::hsi<hsi_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::hsi< category_right_type > hsi_constant_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		,yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	enum {
		hue_p = ::color::place::_internal::hue<category_right_type>::position_enum
		,saturation_p = ::color::place::_internal::saturation<category_right_type>::position_enum
		,intensity_p = ::color::place::_internal::intensity<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<hue_p >(container_right_trait_type::template get<hue_p >(right));
		scalar_type s = normalize_type::template process<saturation_p>(container_right_trait_type::template get<saturation_p>(right));
		scalar_type i = normalize_type::template process<intensity_p >(container_right_trait_type::template get<intensity_p >(right));
		scalar_type min = i * (1 - s);
		int region = int(3 * h);
		h -= region * hsi_constant_type::third();
		h *= hsi_constant_type::two_pi();
		scalar_type n = i*(1+ s*cos(h) / cos(hsi_constant_type::deg60() - h));
		scalar_type r;
		scalar_type g;
		scalar_type b;
		switch(region % 3) {
		case 0:
			r = n;
			b = min;
			g = 3*i-(r+b);
			break;
		case 1:
			g = n;
			r = min;
			b = 3*i-(r+g);
			break;
		case 2:
			b = n;
			g = min;
			r = 3*i-(g+b);
			break;
		}
		container_left_trait_type::template set<cyan_p >(left, diverse_type::template process<cyan_p >(scalar_type(1) - r));
		container_left_trait_type::template set<magenta_p>(left, diverse_type::template process<magenta_p>(scalar_type(1) - g));
		container_left_trait_type::template set<yellow_p >(left, diverse_type::template process<yellow_p >(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename rgb_tag_name >
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::rgb<rgb_tag_name>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::rgb<rgb_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;
	typedef ::color::operation::_internal::invert< category_right_type > invert_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	enum {
		red_p = ::color::place::_internal::red<category_right_type>::position_enum
		,green_p = ::color::place::_internal::green<category_right_type>::position_enum
		,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set< cyan_p>(left, reformat_type::template process< cyan_p,red_p >(invert_type::template component<red_p >(container_right_trait_type::template get<red_p >(right))));
		container_left_trait_type::template set<magenta_p>(left, reformat_type::template process<magenta_p,green_p>(invert_type::template component<green_p>(container_right_trait_type::template get<green_p>(right))));
		container_left_trait_type::template set< yellow_p>(left, reformat_type::template process< yellow_p,blue_p >(invert_type::template component<blue_p >(container_right_trait_type::template get<blue_p >(right))));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename yiq_tag_name >
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::yiq<yiq_tag_name>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::yiq<yiq_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::yiq< category_right_type > yiq_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	enum {
		luma_p = ::color::place::_internal::luma<category_right_type>::position_enum
		, inphase_p = ::color::place::_internal::inphase<category_right_type>::position_enum
		,quadrature_p = ::color::place::_internal::quadrature<category_right_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type a11 = yiq_const_type::a11(), a12 = yiq_const_type::a12(), a13 = yiq_const_type::a13();
		static scalar_type a21 = yiq_const_type::a21(), a22 = yiq_const_type::a22(), a23 = yiq_const_type::a23();
		static scalar_type a31 = yiq_const_type::a31(), a32 = yiq_const_type::a32(), a33 = yiq_const_type::a33();
		scalar_type y = normalize_type::template process< luma_p>(container_right_trait_type::template get< luma_p>(right));
		scalar_type i = normalize_type::template process< inphase_p>(container_right_trait_type::template get< inphase_p>(right));
		scalar_type q = normalize_type::template process<quadrature_p>(container_right_trait_type::template get<quadrature_p>(right));
		i = yiq_const_type::i_diverse(i);
		q = yiq_const_type::q_diverse(q);
		scalar_type r = a11 * y + a12 * i + a13 * q;
		scalar_type g = a21 * y + a22 * i + a23 * q;
		scalar_type b = a31 * y + a32 * i + a33 * q;
		container_left_trait_type::template set< cyan_p>(left, diverse_type::template process< cyan_p>(scalar_type(1) - r));
		container_left_trait_type::template set< magenta_p>(left, diverse_type::template process<magenta_p>(scalar_type(1) - g));
		container_left_trait_type::template set< yellow_p>(left, diverse_type::template process< yellow_p>(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename cmy_tag_name
	,typename yuv_tag_name, ::color::constant::yuv::reference_enum yuv_reference_number
	>
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::yuv<yuv_tag_name, yuv_reference_number>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::yuv<yuv_tag_name, yuv_reference_number> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::yuv::parameter< yuv_tag_name, yuv_reference_number > yuv_parameter_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type const Wr = yuv_parameter_type::Wr();
		static scalar_type const Wb = yuv_parameter_type::Wb();
		static scalar_type const Wg = yuv_parameter_type::Wg();
		static scalar_type const Umax = yuv_parameter_type::Umax();
		static scalar_type const Vmax = yuv_parameter_type::Vmax();
		static scalar_type const b11 = 1, b12 = 0, b13 = (1 - Wr) / Vmax;
		static scalar_type const b21 = 1, b22 = - Wb*(1 - Wb) / Umax / Wg, b23 = -Wr*(1 - Wr) / Vmax / Wg;
		static scalar_type const b31 = 1, b32 = ((1 - Wb) / Umax), b33 = 0;
		scalar_type y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type u = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type v = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		u = (u - scalar_type(0.5)) * scalar_type(2) * Umax;
		v = (v - scalar_type(0.5)) * scalar_type(2) * Vmax;
		scalar_type r = y + v * b13;
		scalar_type g = y + u * b22 + v * b23;
		scalar_type b = y + u * b32 ;
		container_left_trait_type::template set< cyan_p>(left, diverse_type::template process< cyan_p>(scalar_type(1) - r));
		container_left_trait_type::template set<magenta_p>(left, diverse_type::template process<magenta_p>(scalar_type(1) - g));
		container_left_trait_type::template set< yellow_p>(left, diverse_type::template process< yellow_p>(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename YCgCo_tag_name >
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::YCgCo< YCgCo_tag_name>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::YCgCo<YCgCo_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::YCgCo< category_right_type > YCgCo_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		cyan_p = ::color::place::_internal:: cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal:: yellow<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type Y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type Cg = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type Co = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		Cg = YCgCo_const_type::Cg_diverse(Cg);
		Co = YCgCo_const_type::Co_diverse(Co);
		scalar_type r = Y - Cg + Co;
		scalar_type g = Y + Cg;
		scalar_type b = Y - Cg - Co;
		container_left_trait_type::template set< cyan_p>(left, diverse_type::template process< cyan_p>(scalar_type(1) - r));
		container_left_trait_type::template set<magenta_p>(left, diverse_type::template process<magenta_p>(scalar_type(1) - g));
		container_left_trait_type::template set< yellow_p>(left, diverse_type::template process< yellow_p>(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename YDbDr_tag_name >
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::YDbDr< YDbDr_tag_name>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::YDbDr<YDbDr_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::YDbDr< category_right_type > YDbDr_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type const Wr = YDbDr_const_type::Wr();
		static scalar_type const Wb = YDbDr_const_type::Wb();
		static scalar_type const Wg = YDbDr_const_type::Wg();
		static scalar_type const Umax = YDbDr_const_type::Umax();
		static scalar_type const Vmax = YDbDr_const_type::Vmax();
		static scalar_type const b11 = 1, b12 = 0, b13 = (1 - Wr) / Vmax;
		static scalar_type const b21 = 1, b22 = - Wb*(1 - Wb) / Umax / Wg, b23 = -Wr*(1 - Wr) / Vmax / Wg;
		static scalar_type const b31 = 1, b32 = ((1 - Wb) / Umax), b33 = 0;
		scalar_type Y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type Db = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type Dr = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type u = YDbDr_const_type::DB_diverse(Db) / YDbDr_const_type::DB_scale();
		scalar_type v = YDbDr_const_type::DR_diverse(Dr) / YDbDr_const_type::DR_scale();
		scalar_type r = Y + v * b13;
		scalar_type g = Y + u * b22 + v * b23;
		scalar_type b = Y + u * b32;
		container_left_trait_type::template set< cyan_p>(left, diverse_type::template process< cyan_p>(scalar_type(1) - r));
		container_left_trait_type::template set<magenta_p>(left, diverse_type::template process<magenta_p>(scalar_type(1) - g));
		container_left_trait_type::template set< yellow_p>(left, diverse_type::template process< yellow_p>(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename cmy_tag_name
	,typename YPbPr_tag_name, ::color::constant::YPbPr::reference_enum YPbPr_reference_number
	>
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::YPbPr< YPbPr_tag_name, YPbPr_reference_number>
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::YPbPr<YPbPr_tag_name, YPbPr_reference_number> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::YPbPr::parameter< YPbPr_tag_name, YPbPr_reference_number > YPbPr_parameter_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	enum {
		cyan_p = ::color::place::_internal::cyan<category_left_type>::position_enum
		,magenta_p = ::color::place::_internal::magenta<category_left_type>::position_enum
		, yellow_p = ::color::place::_internal::yellow<category_left_type>::position_enum
	};

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type Y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type Pb = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type Pr = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		Pb = YPbPr_parameter_type::Pb_diverse(Pb);
		Pr = YPbPr_parameter_type::Pr_diverse(Pr);
		scalar_type r = YPbPr_parameter_type::a11() * Y + YPbPr_parameter_type::a12() * Pb + YPbPr_parameter_type::a13() * Pr;
		scalar_type g = YPbPr_parameter_type::a21() * Y + YPbPr_parameter_type::a22() * Pb + YPbPr_parameter_type::a23() * Pr;
		scalar_type b = YPbPr_parameter_type::a31() * Y + YPbPr_parameter_type::a32() * Pb + YPbPr_parameter_type::a33() * Pr;
		container_left_trait_type::template set< cyan_p>(left, diverse_type::template process< cyan_p>(scalar_type(1) - r));
		container_left_trait_type::template set<magenta_p>(left, diverse_type::template process<magenta_p>(scalar_type(1) - g));
		container_left_trait_type::template set< yellow_p>(left, diverse_type::template process< yellow_p>(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template
<
	typename cmy_tag_name
	,typename xyz_tag_name
	>
struct convert
	<
	::color::category::cmy< cmy_tag_name >
	,::color::category::xyz< xyz_tag_name >
	> {
public:
	typedef ::color::category::cmy< cmy_tag_name > cmy_category_type, category_left_type;
	typedef ::color::category::xyz< xyz_tag_name > xyz_category_type, category_right_type;

	typedef typename ::color::akin::rgb< xyz_category_type >::akin_type rgb_category_type;

	typedef ::color::model< cmy_category_type > cmy_model_type;
	typedef ::color::model< xyz_category_type > xyz_model_type;

	typedef ::color::model< rgb_category_type > rgb_model_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		left = cmy_model_type(rgb_model_type(xyz_model_type(right))).container();
	}
};

}
}

namespace color {
namespace operation {
namespace _internal {

template< typename category_name>
struct addition {
public:
	typedef category_name category_type;

	typedef ::color::trait::container< category_type > container_trait_type;
	typedef ::color::trait::index< category_type > index_trait_type;
	typedef ::color::model<category_type> model_type;

	typedef typename index_trait_type::instance_type index_type;

	static model_type & process(model_type &result, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, result.get(index) + right.get(index));
		}
		return result;
	}

	static model_type & process(model_type &result, model_type const& left, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, left.get(index) + right.get(index));
		}
		return result;
	}
};

}

template< typename category_name >
::color::model<category_name> &
addition
(
	::color::model<category_name> & result
	,::color::model<category_name> const& right
) {
	return ::color::operation::_internal::addition<category_name>::process(result, right);
}

template< typename category_name >
::color::model<category_name> &
addition
(
	::color::model<category_name> & result
	,::color::model<category_name> const& left
	,::color::model<category_name> const& right
) {
	return ::color::operation::_internal::addition<category_name>::process(result, left, right);
}

}
}

namespace color {
namespace operation {
namespace _internal {
template< typename category_name >
struct subtract {
public:
	typedef category_name category_type;

	typedef ::color::trait::index<category_type> index_trait_type;
	typedef ::color::trait::container< category_type > container_trait_type;

	typedef ::color::model<category_type> model_type;

	typedef typename index_trait_type::instance_type index_type;

	static model_type & process(model_type &result, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, result.get(index) - right.get(index));
		}
		return result;
	}

	static model_type & process(model_type &result, model_type const& left, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, left.get(index) - right.get(index));
		}
		return result;
	}

};
}

template< typename category_name >
::color::model<category_name> & subtract
(
	::color::model<category_name> & result
	,color::model<category_name> const& right
) {
	return ::color::operation::_internal::subtract<category_name>::process(result, right);
}

template< typename category_name >
::color::model<category_name> & subtract
(
	::color::model<category_name> & result
	,color::model<category_name> const& left
	,color::model<category_name> const& right
) {
	return ::color::operation::_internal::subtract<category_name>::process(result, left, right);
}

}
}

namespace color {
namespace operation {
namespace arithmetic {

template< typename category_name >
inline
::color::model< category_name >
operator +(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
	::color::model< category_name > result;
	::color::operation::addition(result, left, right);
	return result;
}

template< typename category_name>
inline
::color::model< category_name > &
operator +=(::color::model< category_name > & result, ::color::model< category_name > const& right) {
	::color::operation::addition(result, right);
	return result;
}

template< typename category_name >
inline
::color::model< category_name >
operator -(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
	::color::model< category_name > result;
	::color::operation::subtract(result, left, right);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::model< category_name >
operator *
(
	scalar_name const& left
	,::color::model< category_name > const& right
) {
	::color::model< category_name > result;
	::color::operation::scale(result, left, right);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::model< category_name >
operator *
(
	::color::model< category_name > const & left
	,scalar_name const & right
) {
	::color::model< category_name > result;
	::color::operation::scale(result, right, left);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::model< category_name >
operator /
(
	::color::model< category_name > const & left
	,scalar_name const & right
) {
	::color::model< category_name > result;
	::color::operation::scale(result, scalar_name(1) / right, left);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::model< category_name > &
operator -=(::color::model< category_name > & result, scalar_name const& left) {
	::color::operation::subtract(result, left);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::model< category_name > &
operator *=(::color::model< category_name > & result, scalar_name const& scalar) {
	::color::operation::scale(result, scalar);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::model< category_name > &
operator /=(::color::model< category_name > & result, scalar_name const& scalar) {
	::color::operation::scale(result, scalar_name(1) / scalar);
	return result;
}

}

}
}

namespace color {
namespace operation {
namespace _internal {

template< typename category_name >
struct convex {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;

	typedef scalar_type const& scalar_const_input_type;

	typedef ::color::trait::index<category_type> index_trait_type;
	typedef ::color::trait::container< category_type > container_trait_type;
	typedef ::color::model<category_type> model_type;

	typedef model_type & model_input_type;
	typedef model_type const& model_const_input_type;

	typedef typename index_trait_type::instance_type index_type;

	static model_type & process(model_input_type result, scalar_const_input_type scalar, model_const_input_type right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, scalar * result.get(index) +(scalar_type(1) - scalar) *right.get(index));
		}
		return result;
	}

	static model_type & process(model_input_type result, model_const_input_type left, scalar_const_input_type scalar, model_const_input_type right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, scalar * left.get(index) +(scalar_type(1) - scalar) *right.get(index));
		}
		return result;
	}

};
}

template< typename category_name >
::color::model<category_name> &
convex
(
	::color::model<category_name> & result
	,typename ::color::trait::scalar<category_name>::input_const_type scalar
	,color::model<category_name> const& right
) {
	return ::color::operation::_internal::convex<category_name>::process(result, scalar, right);
}

template< typename category_name >
::color::model<category_name> &
convex
(
	::color::model<category_name> & result
	,color::model<category_name> const& left
	,typename ::color::trait::scalar<category_name>::input_const_type scalar
	,color::model<category_name> const& right
) {
	return ::color::operation::_internal::convex<category_name>::process(result, left, scalar, right);
}

}
}

namespace color {
namespace operation {
namespace _internal {

template
<
	typename category_name
	>
struct blend {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::trait::scalar<category_type>::input_const_type scalar_const_input_type;

	typedef ::color::trait::index< category_type > index_trait_type;
	typedef typename index_trait_type::instance_type index_type;

	typedef ::color::trait::container< category_type > container_trait_type;

	typedef ::color::model<category_type> model_type;

	typedef ::color::_internal::diverse< category_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;

	typedef ::color::operation::_internal::blend<category_type> this_type;

	static model_type & accumulate(model_type &result, scalar_type const& alpha, model_type const& upper) {
		return this_type::template accumulate(result, result, alpha, upper);
	}

	static model_type & accumulate(model_type &result, model_type const& lower, scalar_type const& alpha, model_type const& upper) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, (scalar_type(1) - alpha) * lower.get(index) + alpha * upper.get(index));
		}
		return result;
	}

	template< index_type alpha_index >
	static model_type & accumulate(model_type &result, model_type const& upper) {
		return this_type::template accumulate<alpha_index>(result, result, upper);
	}

	template< index_type alpha_index >
	static model_type & accumulate(model_type &result, model_type const& lower, model_type const& upper) {
		scalar_type aU = normalize_type::template process<alpha_index>(::color::get::alpha(upper));
		scalar_type aL = normalize_type::template process<alpha_index>(::color::get::alpha(lower));
		scalar_type divisor = aU + aL*(scalar_type(1) - aU);
		scalar_type cU = aU/divisor;
		scalar_type cL = aL * (scalar_type(1) - aU) / divisor;
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, cL * lower.get(index) + cU * upper.get(index));
		}
		::color::set::alpha(result, diverse_type::template process<alpha_index>(divisor));
		return result;
	}

	static model_type mix(model_type const& lower, scalar_type const& alpha, model_type const& upper) {
		model_type result;
		this_type::template accumulate(result, lower, alpha, upper);
		return result;
	}

	template< index_type alpha_index >
	static model_type mix(model_type const& lower, model_type const& upper) {
		model_type result;
		this_type::template accumulate<alpha_index>(result, lower, upper);
		return result;
	}
};

}

template< typename category_name >
inline
::color::model<category_name> &
blend
(
	::color::model<category_name> & result
	,::color::model<category_name> const& upper
				   ) {
	enum { alpha_index = ::color::place::_internal::alpha<category_name>::position_enum };
	static_assert(0 <= alpha_index, "Error: This combination of model/format has no alpha channel") ;
	return ::color::operation::_internal::blend<category_name>::template accumulate< alpha_index >(result, upper);
}

template< typename category_name >
inline
::color::model<category_name> &
blend
(
	::color::model<category_name> & result
	,::color::model<category_name> const& lower
	,::color::model<category_name> const& upper
				   ) {
	enum { alpha_index = ::color::place::_internal::alpha<category_name>::position_enum };
	static_assert(0 <= alpha_index, "Error: This combination of model/format has no alpha channel") ;
	return ::color::operation::_internal::blend<category_name>::template accumulate< alpha_index >(result, lower, upper);
}

template< typename category_name >
::color::model<category_name>
mix
(
	::color::model<category_name> const& lower
	,::color::model<category_name> const& upper
				   ) {
	enum { alpha_index = ::color::place::_internal::alpha<category_name>::position_enum };
	static_assert(0 <= alpha_index, "Error: This combination of model/format has no alpha channel") ;
	return ::color::operation::_internal::blend<category_name>::template mix< alpha_index >(lower, upper);
}

template< typename category_name >
inline
::color::model<category_name> &
blend
(
	::color::model<category_name> & result
	,typename ::color::trait::scalar<category_name>::input_const_type alpha
	,::color::model<category_name> const& upper
				   ) {
	return ::color::operation::_internal::blend<category_name>::accumulate(result, alpha, upper);
}

template< typename category_name >
inline
::color::model<category_name> &
blend
(
	::color::model<category_name> & result
	,::color::model<category_name> const& lower
	,typename ::color::trait::scalar<category_name>::input_const_type alpha
	,::color::model<category_name> const& upper
				   ) {
	return ::color::operation::_internal::blend<category_name>::accumulate(result, lower, alpha, upper);
}

template< typename category_name >
::color::model<category_name>
mix
(
	::color::model<category_name> const& lower
	,typename ::color::trait::scalar<category_name>::input_const_type alpha
	,::color::model<category_name> const& upper
				   ) {
	return ::color::operation::_internal::blend<category_name>::mix(lower, alpha, upper);
}

}
}

namespace color {
	namespace operation {
		namespace _internal {

			template
			<
				typename category_name
				>
			struct combine {
				public:
				typedef category_name category_type;

				typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
				typedef typename ::color::trait::index<category_type>::instance_type index_type;

				typedef ::color::trait::container< category_type > container_trait_type;
				typedef typename ::color::trait::component< category_name >::instance_type component_type;

				typedef ::color::model<category_type> model_type;

				static model_type & process
				(
					model_type & result
					,scalar_type const& a0
					,model_type const& c0
					,scalar_type const& a1
					,model_type const& c1
	) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, component_type(a0 * c0.get(index) + a1 * c1.get(index)));
		}
		return result;
	}

	static model_type & process
	(
		model_type & result
		,scalar_type const& a0
		,model_type const& c0
		,scalar_type const& a1
		,model_type const& c1
		,scalar_type const& a2
		,model_type const& c2
	) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, component_type(a0 * c0.get(index) + a1 * c1.get(index) + a2 * c2.get(index)));
		}
		return result;
	}

	   };

	   }

	template< typename category_name >
	::color::model<category_name> &
	combine
	(
		::color::model<category_name> & result
		,typename ::color::trait::scalar<category_name>::input_const_type a0
		,::color::model<category_name> const& c0
		,typename ::color::trait::scalar<category_name>::input_const_type a1
		,::color::model<category_name> const& c1
					   ) {
		return ::color::operation::_internal::combine<category_name>::process(result, a0, c0, a1, c1);
	}

	template< typename category_name >
	::color::model<category_name> &
	combine
	(
		::color::model<category_name> & result
		,typename ::color::trait::scalar<category_name>::input_const_type a0
		,::color::model<category_name> const& c0
		,typename ::color::trait::scalar<category_name>::input_const_type a1
		,::color::model<category_name> const& c1
		,typename ::color::trait::scalar<category_name>::input_const_type a2
		,::color::model<category_name> const& c2
					   ) {
		return ::color::operation::_internal::combine<category_name>::process(result, a0, c0, a1, c1, a2, c2);
	}

												 }
}

namespace color {
	namespace operation {
		namespace _internal {

			template< typename category_name >
			struct bias {
				public:
				typedef category_name category_type;

				typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
				typedef typename ::color::trait::scalar<category_type>::input_const_type scalar_const_input_type;

				typedef ::color::trait::index<category_type> index_trait_type;
				typedef typename index_trait_type::instance_type index_type;

				typedef ::color::trait::container< category_type > container_trait_type;

				typedef ::color::model<category_type> model_type;
				typedef model_type & model_input_type;
				typedef model_type const& model_const_input_type;

				typedef ::color::_internal::diverse< category_type > diverse_type;
				typedef ::color::_internal::normalize< category_type > normalize_type;

				typedef ::color::operation::_internal::bias< category_name > this_type;

	static model_type & process(model_input_type result, scalar_const_input_type scalar) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, diverse_type::process(this_type::process(normalize_type::process(result.get(index), index), scalar), index));
		}
		return result;
	}

	static model_type & process(model_input_type result, model_const_input_type left, scalar_const_input_type value) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, diverse_type::process(this_type::process(normalize_type::process(left.get(index), index), value), index));
		}
		return result;
	}

	template< index_type index_number >
	static model_type & process(model_input_type result, model_const_input_type left, scalar_const_input_type scalar) {
		result.template set<index_number>(diverse_type::template process<index_number>(this_type::process(normalize_type::template process<index_number>(left.template get<index_number>()), scalar)));
		return result;
	}

	static scalar_type process(scalar_const_input_type x, scalar_const_input_type b) {
		return pow(x, log(b) / log(scalar_type(0.5)));
	}

																				  };
																	}

	template< typename category_name >
	::color::model<category_name> &
	bias
	(
		::color::model<category_name> & result
		,typename ::color::trait::scalar<category_name>::input_const_type const& scalar
										) {
		return ::color::operation::_internal::bias<category_name>::process(result, scalar);
	}

	template< typename category_name>
	::color::model<category_name> &
	bias
	(
		::color::model<category_name> & result
		,color::model<category_name> const& left
		,typename ::color::trait::scalar<category_name>::input_const_type const& scalar
										) {
		return ::color::operation::_internal::bias<category_name>::process(result, left, scalar);
	}

											  }
}

namespace color {
	namespace operation {
		namespace _internal {

			template< typename category_name >
			struct gain {
				public:
				typedef category_name category_type;

				typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
				typedef typename ::color::trait::scalar<category_type>::input_const_type scalar_const_input_type;

				typedef ::color::trait::index<category_type> index_trait_type;
				typedef typename index_trait_type::instance_type index_type;

				typedef ::color::trait::container< category_type > container_trait_type;

				typedef ::color::model<category_type> model_type;
				typedef model_type & model_input_type;
				typedef model_type const& model_const_input_type;

				typedef ::color::_internal::diverse< category_type > diverse_type;
				typedef ::color::_internal::normalize< category_type > normalize_type;

				typedef ::color::operation::_internal::bias< category_name > bias_type;

				typedef ::color::operation::_internal::gain< category_name > this_type;

	static model_type & process(model_input_type result, scalar_const_input_type scalar) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, diverse_type::process(this_type::process(normalize_type::process(result.get(index), index), scalar), index));
		}
		return result;
	}

	static model_type & process(model_input_type result, model_const_input_type left, scalar_const_input_type value) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, diverse_type::process(this_type::process(normalize_type::process(left.get(index), index), value), index));
		}
		return result;
	}

	template< index_type index_number >
	static model_type & process(model_input_type result, model_const_input_type left, scalar_const_input_type scalar) {
		result.template set<index_number>(diverse_type::template process<index_number>(this_type::process(normalize_type::template process<index_number>(left.template get<index_number>()), scalar)));
		return result;
	}

	static scalar_type process(scalar_const_input_type x, scalar_const_input_type g) {
		if(x < scalar_type(0.5)) {
			return bias_type::process(scalar_type(1)-g, scalar_type(2)*x)/scalar_type(2);
		} else {
			return scalar_type(1) - bias_type::process(scalar_type(1)-g,scalar_type(2) - scalar_type(2)*x)/scalar_type(2);
		}
	}

	  };
																				  }

	template< typename category_name >
	::color::model<category_name> &
	gain
	(
		::color::model<category_name> & result
		,typename ::color::trait::scalar<category_name>::input_const_type const& scalar
										) {
		return ::color::operation::_internal::gain<category_name>::process(result, scalar);
	}

	template< typename category_name >
	::color::model<category_name> &
	gain
	(
		::color::model<category_name> & result
		,::color::model<category_name> const& left
		,typename ::color::trait::scalar<category_name>::input_const_type const& scalar
										) {
		return ::color::operation::_internal::gain<category_name>::process(result, left, scalar);
	}
											  }
}

namespace color {
	namespace compare {

		template < typename category_name >
		bool equal
		(
			::color::model< category_name > const& left
			,::color::model< category_name > const& right
	) {
		return left.container() == right.container();
	}

	namespace operators {

		template< typename category_name >
		inline
		bool
	operator ==(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
		return ::color::compare::equal(left, right);
	}

								  }
				   }
}
namespace color {
	namespace compare {

		template < typename category_name >
		bool different
		(
			::color::model< category_name > const& left
			,::color::model< category_name > const& right
	) {
		return left.container() != right.container();
	}

	namespace operators {

		template< typename category_name >
		inline
		bool
	operator !=(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
		return ::color::compare::different(left, right);
	}

								  }
				   }
}

namespace color {
	namespace compare {

		template < typename category_name >
		bool great_or_equal
		(
			::color::model< category_name > const& left
			,::color::model< category_name > const& right
	) {
		return left.container() >= right.container();
	}

	namespace operators {

		template< typename category_name >
		inline
		bool
	operator >=(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
		return ::color::compare::great_or_equal(left, right);
	}
								  }

				   }
}
namespace color {
	namespace compare {

		template < typename category_name >
		bool great_strict
		(
			::color::model< category_name > const& left
			,::color::model< category_name > const& right
	) {
		return left.container() > right.container();
	}

	namespace operators {

		template< typename category_name >
		inline
		bool
		operator >(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
		return ::color::compare::great_strict(left, right);
	}

								 }
				  }
}
namespace color {
	namespace compare {

		template < typename category_name >
		bool less_or_equal
		(
			::color::model< category_name > const& left
			,::color::model< category_name > const& right
	) {
		return left.container() <= right.container();
	}

	namespace operators {

		template< typename category_name >
		inline
		bool
	operator <=(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
		return ::color::compare::less_or_equal(left, right);
	}

								  }
				   }
}
namespace color {
	namespace compare {

		template < typename category_name >
		bool less_strict
		(
			::color::model< category_name > const& left
			,::color::model< category_name > const& right
	) {
		return left.container() < right.container();
	}

	namespace operators {

		template< typename category_name >
		inline
		bool
	operator <(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
		return ::color::compare::less_strict(left, right);
	}

								 }
				  }
}

namespace color {
	namespace compare {

		template < typename category_name >
	bool darker(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
		using namespace ::color::compare::operators;
		typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;
		return ::color::gray<scalar_type>(left).container() < ::color::gray<scalar_type>(right).container();
	}

																	   }
}

namespace color {
	namespace compare {

		template < typename category_name >
	bool brighter(::color::model< category_name > const& left, ::color::model< category_name > const& right) {
		using namespace ::color::compare::operators;
		typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;
		return ::color::gray<scalar_type>(left).container() > ::color::gray<scalar_type>(right).container();
	}

																	   }
}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::black_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::black_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0x00, 0x00, 0x00 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {
	namespace make {

		template< typename category_name >
		void gray
		(
			::color::model< category_name > & color_parameter
			,typename ::color::trait::scalar< category_name >::input_const_type percent_param
	) {
		typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;
		typedef ::color::gray<scalar_type> gray_type;
		color_parameter = gray_type{ percent_param / scalar_type(100) };
	}

	template< typename category_name >
	::color::model< category_name >
	gray
	(
		typename ::color::trait::scalar< category_name >::input_const_type percent_param
									   ) {
		typedef ::color::model< category_name > model_type;
		model_type color_return;
		::color::make::gray(color_return, percent_param);
		return color_return;
	}

	template< typename category_name >
	::color::model< category_name >
	gray
	(
		typename ::color::trait::scalar< category_name >::input_const_type percent_param
		, category_name category_param
									   ) {
		typedef ::color::model< category_name > model_type;
		model_type color_return;
		::color::make::gray(color_return, percent_param);
		return color_return;
	}

						  }

	namespace constant {

		template< typename category_name, std::uintmax_t black_number, std::uintmax_t white_number >
		struct make< ::color::constant::gray_t<black_number,white_number>, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::gray<double> gray_type;

			typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

			typedef ::color::constant::gray_t<black_number,white_number> constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ gray_type{ scalar_type(white_number)/scalar_type(black_number+white_number) } };
		container = s_model.container();
	}
													  };

											 }

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::white_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::white_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 1, 1, 1 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::red_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::red_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 1, 0, 0 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::green_t, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::green_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0, 0.5, 0 } };
		container = s_model.container();
	}

													  };

	template< typename category_name >
	struct make<::color::constant::x11::green_t, category_name > {
		typedef category_name category_type;
		typedef ::color::model<category_type> model_type;
		typedef ::color::rgb<double> rgb_type;
		typedef ::color::constant::x11::green_t constant_type;

		typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0, 1, 0 } };
		container = s_model.container();
	}
												  };

							}

}

namespace color {
	namespace constant {

		template< typename category_name >
		struct make<::color::constant::blue_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::blue_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0, 0, 1 } };
		container = s_model.container();
	}

													  };

								}
}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::cyan_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::cyan_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0x00, 0xFF, 0xFF } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::magenta_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::magenta_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 1, 0, 1 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::yellow_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::yellow_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 1, 1, 0 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make< ::color::constant::aqua_t, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::aqua_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0x00, 0xFF, 0xFF } };
		container = s_model.container();
	}

													  };

								}
}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::fuchsia_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::fuchsia_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 1, 0, 1 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::lime_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::lime_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0, 1, 0 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make< ::color::constant::maroon_t, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::maroon_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.5, 0, 0 } };
		container = s_model.container();
	}
													  };

	template< typename category_name >
	struct make< ::color::constant::x11::maroon_t, category_name > {
		typedef category_name category_type;
		typedef ::color::model<category_type> model_type;
		typedef ::color::rgb<double> rgb_type;
		typedef ::color::constant::x11::maroon_t constant_type;

		typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.69, 0.19, 0.38 } };
		container = s_model.container();
	}
												  };

							}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::navy_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::navy_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0, 0, 0.5 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::olive_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::olive_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.5, 0.5, 0 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::orange_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::orange_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 1, 0.65, 0 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::purple_t, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::purple_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.5, 0, 0.5 } };
		container = s_model.container();
	}
													  };

	template< typename category_name >
	struct make<::color::constant::x11::purple_t, category_name > {
		typedef category_name category_type;
		typedef ::color::model<category_type> model_type;
		typedef ::color::rgb<double> rgb_type;
		typedef ::color::constant::x11::purple_t constant_type;

		typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.63, 0.13, 0.94 } };
		container = s_model.container();
	}
												  };

							}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::silver_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::silver_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.75, 0.75, 0.75 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::teal_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::teal_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0, 0.5, 0.5 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::violet_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb< std::uint8_t > rgb_type;
			typedef ::color::constant::violet_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xEE, 0x82, 0xEE } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::aquamarine_t, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::aquamarine_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.5, 1, 212.0/255.0 } };
		container = s_model.container();
	}

													  };

								}
}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::azure_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::azure_type constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.9375, 1, 1 } };
		container = s_model.container();
	}

													  };

								}
}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::beige_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::beige_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xF5, 0xF5, 0xDC } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::bisque_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::bisque_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 1, 0.875, 0.75 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::brown_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::brown_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xA5, 0x2A, 0x2A } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::chocolate_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::chocolate_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xD2, 0x69, 0x1E } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::coral_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::coral_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 1, 0.5, 0.31 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::crimson_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::crimson_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xDC, 0x14, 0x3C } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::gainsboro_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::gainsboro_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xDB, 0xDB, 0xDB } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::gold_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::gold_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xFF, 0xD7, 0x00 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::indigo_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::indigo_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0x4B, 0x00, 0x82 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::ivory_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::ivory_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 1, 1, 0.9375 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::khaki_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::khaki_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.9375, 0.9, 0.55 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::lavender_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::lavender_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xE6, 0xE6, 0xFA } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::linen_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::linen_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 250.0/255.0, 0.9375, 0.9 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::moccasin_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::moccasin_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xFF, 0xE4, 0xB5 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::orchid_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::orchid_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xDA, 0x70, 0xD6 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::peru_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::peru_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.8, 0.52, 0.25 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {
	namespace constant {

		template< typename category_name >
		struct make<::color::constant::pink_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::pink_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xFF, 0xC0, 0xCB } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::plum_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::plum_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xDD, 0xA0, 0xDD } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::salmon_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::salmon_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 250/255.0, 0.5, 114/255.0 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::sienna_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::sienna_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xA0, 0x52, 0x2D } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::snow_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::snow_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xFF, 0xFA, 0xFA } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::tan_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::tan_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xD2, 0xB4, 0x8C } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::thistle_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::thistle_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xD8, 0xBF, 0xD8 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::tomato_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::tomato_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xFF, 0x63, 0x47 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::turquoise_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<double> rgb_type;
			typedef ::color::constant::turquoise_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0.25, 0.875, 0.8125 } };
		container = s_model.container();
	}

													  };

								}

}

namespace color {

	namespace constant {

		template< typename category_name >
		struct make<::color::constant::wheat_type, category_name > {
			typedef category_name category_type;
			typedef ::color::model<category_type> model_type;
			typedef ::color::rgb<std::uint8_t> rgb_type;
			typedef ::color::constant::wheat_t constant_type;

			typedef typename ::color::trait::container<category_type>::output_type container_output_type;

	inline static void process(container_output_type & container) {
		static model_type s_model{ rgb_type{ 0xF5, 0xDE, 0xB3 } };
		container = s_model.container();
	}

													  };

								}

}

using namespace ::color::operation::arithmetic;
using namespace ::color::compare::operators;
