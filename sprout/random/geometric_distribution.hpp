#ifndef SPROUT_RANDOM_GEOMETRIC_DISTRIBUTION_HPP
#define SPROUT_RANDOM_GEOMETRIC_DISTRIBUTION_HPP

#include <ios>
#include <limits>
#include <sprout/config.hpp>
#include <sprout/math/log.hpp>
#include <sprout/math/floor.hpp>
#include <sprout/random/random_result.hpp>
#include <sprout/random/uniform_01.hpp>
#include <sprout/assert.hpp>

namespace sprout {
	namespace random {
		//
		// geometric_distribution
		//
		template<typename IntType = int, typename RealType = double>
		class geometric_distribution {
		public:
			typedef RealType input_type;
			typedef IntType result_type;
		public:
			//
			// param_type
			//
			class param_type {
			public:
				typedef geometric_distribution distribution_type;
			private:
				RealType p_;
			public:
				SPROUT_CONSTEXPR param_type()
					: p_(RealType(0.5))
				{}
				explicit SPROUT_CONSTEXPR param_type(RealType p_arg)
					: p_((SPROUT_ASSERT(RealType(0) < p_arg), SPROUT_ASSERT(p_arg < RealType(1)), p_arg))
				{}
				SPROUT_CONSTEXPR RealType p() const SPROUT_NOEXCEPT {
					return p_;
				}
				template<typename Elem, typename Traits>
				friend std::basic_istream<Elem, Traits>& operator>>(
					std::basic_istream<Elem, Traits>& lhs,
					param_type& rhs
					)
				{
					RealType p;
					if (lhs >> p) {
						if (RealType(0) < p && p < RealType(1)) {
							rhs.p_ = p;
						} else {
							lhs.setstate(std::ios_base::failbit);
						}
					}
					return lhs;
				}
				template<typename Elem, typename Traits>
				friend std::basic_ostream<Elem, Traits>& operator<<(
					std::basic_ostream<Elem, Traits>& lhs,
					param_type const& rhs
					)
				{
					return lhs << rhs.p_;
				}
				friend SPROUT_CONSTEXPR bool operator==(param_type const& lhs, param_type const& rhs) SPROUT_NOEXCEPT {
					return lhs.p_ == rhs.p_;
				}
				friend SPROUT_CONSTEXPR bool operator!=(param_type const& lhs, param_type const& rhs) SPROUT_NOEXCEPT {
					return !(lhs == rhs);
				}
			};
		private:
		public:
			static SPROUT_CONSTEXPR RealType init_log_1mp(RealType p) {
				return sprout::log(1 - p);
			}
		private:
		public:
			RealType p_;
			RealType log_1mp_;
		private:
			template<typename Engine, typename Random>
			SPROUT_CONSTEXPR sprout::random::random_result<Engine, geometric_distribution> generate_1(Random const& rnd) const {
				return sprout::random::random_result<Engine, geometric_distribution>(
					static_cast<IntType>(sprout::floor(sprout::log(RealType(1) - rnd.result()) / log_1mp_)),
					rnd.engine(),
					*this
					);
			}
			template<typename Engine>
			SPROUT_CONSTEXPR sprout::random::random_result<Engine, geometric_distribution> generate(Engine const& eng) const {
				return generate_1<Engine>(sprout::random::uniform_01<RealType>()(eng));
			}
		public:
			SPROUT_CONSTEXPR geometric_distribution()
				: p_(RealType(0.5))
				, log_1mp_(init_log_1mp(RealType(0.5)))
			{}
			explicit SPROUT_CONSTEXPR geometric_distribution(RealType p_arg)
				: p_((SPROUT_ASSERT(RealType(0) < p_arg), SPROUT_ASSERT(p_arg < RealType(1)), p_arg))
				, log_1mp_(init_log_1mp(p_arg))
			{}
			explicit SPROUT_CONSTEXPR geometric_distribution(param_type const& parm)
				: p_(parm.p())
				, log_1mp_(init_log_1mp(parm.p()))
			{}
			SPROUT_CONSTEXPR result_type p() const SPROUT_NOEXCEPT {
				return p_;
			}
			SPROUT_CONSTEXPR result_type min() const SPROUT_NOEXCEPT {
				return 0;
			}
			SPROUT_CONSTEXPR result_type max() const SPROUT_NOEXCEPT {
				return std::numeric_limits<result_type>::max();
			}
			SPROUT_CONSTEXPR param_type param() const SPROUT_NOEXCEPT {
				return param_type(p_);
			}
			void param(param_type const& parm) {
				p_ = parm.p();
				log_1mp_ = init_log_1mp(p_);
			}
			template<typename Engine>
			SPROUT_CONSTEXPR sprout::random::random_result<Engine, geometric_distribution> operator()(Engine const& eng) const {
				return generate(eng);
			}
			template<typename Elem, typename Traits>
			friend std::basic_istream<Elem, Traits>& operator>>(
				std::basic_istream<Elem, Traits>& lhs,
				geometric_distribution& rhs
				)
			{
				param_type parm;
				if (lhs >> parm) {
					rhs.param(parm);
				}
				return lhs;
			}
			template<typename Elem, typename Traits>
			friend std::basic_ostream<Elem, Traits>& operator<<(
				std::basic_ostream<Elem, Traits>& lhs,
				geometric_distribution const& rhs
				)
			{
				return lhs << rhs.param();
			}
			friend SPROUT_CONSTEXPR bool operator==(geometric_distribution const& lhs, geometric_distribution const& rhs) SPROUT_NOEXCEPT {
				return lhs.param() == rhs.param();
			}
			friend SPROUT_CONSTEXPR bool operator!=(geometric_distribution const& lhs, geometric_distribution const& rhs) SPROUT_NOEXCEPT {
				return !(lhs == rhs);
			}
		};
	}	// namespace random

	using sprout::random::geometric_distribution;
}	// namespace sprout

#endif // #ifndef SPROUT_RANDOM_GEOMETRIC_DISTRIBUTION_HPP
