/***********************************************************************************************************************
*                                                                                                                      *
* ngscopeclient                                                                                                        *
*                                                                                                                      *
* Copyright (c) 2012-2023 Andrew D. Zonenberg                                                                          *
* All rights reserved.                                                                                                 *
*                                                                                                                      *
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the     *
* following conditions are met:                                                                                        *
*                                                                                                                      *
*    * Redistributions of source code must retain the above copyright notice, this list of conditions, and the         *
*      following disclaimer.                                                                                           *
*                                                                                                                      *
*    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the       *
*      following disclaimer in the documentation and/or other materials provided with the distribution.                *
*                                                                                                                      *
*    * Neither the name of the author nor the names of any contributors may be used to endorse or promote products     *
*      derived from this software without specific prior written permission.                                           *
*                                                                                                                      *
* THIS SOFTWARE IS PROVIDED BY THE AUTHORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED   *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL *
* THE AUTHORS BE HELD LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES        *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR       *
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                                                                          *
*                                                                                                                      *
***********************************************************************************************************************/

/**
	@file
	@author Andrew D. Zonenberg
	@brief Declaration of TimebasePropertiesDialog
 */
#ifndef TimebasePropertiesDialog_h
#define TimebasePropertiesDialog_h

#include "Dialog.h"

class TimebasePropertiesPage
{
public:
	TimebasePropertiesPage(Oscilloscope* scope);

	Oscilloscope* m_scope;

	//Sample rate
	std::vector<uint64_t> m_rates;
	std::vector<std::string> m_rateNames;
	int m_rate;

	//Memory depth
	std::vector<uint64_t> m_depths;
	std::vector<std::string> m_depthNames;
	int m_depth;

	//Sampling mode
	//(only valid if both RT and equivalent are available)
	int m_samplingMode;

	//Frequency domain controls
	std::string m_centerText;
	double m_center;

	std::string m_spanText;
	double m_span;

	std::string m_startText;
	double m_start;

	std::string m_endText;
	double m_end;

	//Spectrometer controls
	std::string m_integrationText;
	double m_integrationTime;

	bool m_interleaving;
};

class TimebasePropertiesDialog : public Dialog
{
public:
	TimebasePropertiesDialog(Session* session);
	virtual ~TimebasePropertiesDialog();

	void Refresh();

	virtual bool DoRender();

protected:
	Session* m_session;

	std::vector<std::unique_ptr<TimebasePropertiesPage>> m_pages;
};

#endif // TimebasePropertiesDialog_h
