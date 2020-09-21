// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <2out/Match.h>

namespace goost { class Source; }

class SourceMatch final : public oout::Match {
public:
	explicit SourceMatch(const std::shared_ptr<const goost::Source> &source);

	std::unique_ptr<const oout::Result> match(
		const std::shared_ptr<const oout::Text> &b
	) const override;

private:
	const std::shared_ptr<const goost::Source> source;
};
