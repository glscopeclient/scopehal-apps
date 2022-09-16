/***********************************************************************************************************************
*                                                                                                                      *
* glscopeclient                                                                                                        *
*                                                                                                                      *
* Copyright (c) 2012-2022 Andrew D. Zonenberg                                                                          *
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
	@brief Declaration of WaveformArea
 */
#ifndef WaveformArea_h
#define WaveformArea_h

class WaveformArea;
class WaveformGroup;
class MainWindow;

/**
	@brief Drag context for a waveform being dragged
 */
class WaveformDragContext
{
public:
	WaveformDragContext(WaveformArea* src)
	: m_sourceArea(src)
	, m_streamIndex(0)
	{}

	WaveformArea* m_sourceArea;
	size_t m_streamIndex;
};

/**
	@brief Placeholder for a single channel being displayed within a WaveformArea
 */
class DisplayedChannel
{
public:
	DisplayedChannel(StreamDescriptor stream)
		: m_stream(stream)
	{}

	std::string GetName()
	{ return m_stream.GetName(); }

	StreamDescriptor GetStream()
	{ return m_stream; }

protected:
	StreamDescriptor m_stream;
};

/**
	@brief A WaveformArea is a plot that displays one or more OscilloscopeChannel's worth of data

	WaveformArea's auto resize, and will collectively fill the entire client area of their parent window.
 */
class WaveformArea
{
public:
	WaveformArea(StreamDescriptor stream, std::shared_ptr<WaveformGroup> group, MainWindow* parent);
	virtual ~WaveformArea();

	bool Render(int iArea, int numAreas, ImVec2 clientArea);

	StreamDescriptor GetStream(size_t i)
	{ return m_displayedChannels[i]->GetStream(); }

	void AddStream(StreamDescriptor desc);

	void RemoveStream(size_t i);

protected:
	void DraggableButton(std::shared_ptr<DisplayedChannel> chan, size_t index);

	void CenterDropArea(ImVec2 start, ImVec2 size);
	void EdgeDropArea(const std::string& name, ImVec2 start, ImVec2 size, ImGuiDir splitDir);

	/**
		@brief The channels currently living within this WaveformArea

		TODO: make this a FlowGraphNode and just hook up inputs
	 */
	std::vector<std::shared_ptr<DisplayedChannel>> m_displayedChannels;

	///@brief Drag context for waveform we're dragging
	WaveformDragContext m_dragContext;

	///@brief Waveform group containing us
	std::shared_ptr<WaveformGroup> m_group;

	///@brief Top level window object containing us
	MainWindow* m_parent;
};

#endif


