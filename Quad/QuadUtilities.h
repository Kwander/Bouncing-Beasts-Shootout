#pragma once

#ifdef QUAD_MS_COMPILER
	#ifdef QUAD_LIB
		#define QUAD_API __declspec(dllexport)
	#else
		#define QUAD_API __declspec(dllimport)
	#endif
#else
	#define QUAD_API
#endif


#if QUAD_DEBUG==2
	#define QUAD_LOG(x) std::cout<<x<<std::endl;
	#define QUAD_ERROR(x) std::cout << x <<std::endl;
#elif QUAD_DEBUG==1
	#define QUAD_LOG(x)
	#define QUAD_ERROR(x) std::cout << x <<std::endl;
#else
	#define QUAD_LOG(x)
	#define QUAD_ERROR(x)
#endif