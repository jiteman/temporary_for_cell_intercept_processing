#pragma once

#include "jmsf/mtf/Runnable.h"
#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace processing {

class PreliminaryVoiceFileAndKeyMatchFinder :
	public virtual ::jmsf::mtf::Runnable,
	public virtual ::jmsf::Object
{

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static PreliminaryVoiceFileAndKeyMatchFinder *getNull() throw();
	static PreliminaryVoiceFileAndKeyMatchFinder *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace processing
} // namespace mdm
} // namespace nppntt
