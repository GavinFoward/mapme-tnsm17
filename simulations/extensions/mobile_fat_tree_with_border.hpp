#ifndef MOBILE_FAT_TREE_TOPOLOGY_HPP
#define MOBILE_FAT_TREE_TOPOLOGY_HPP
/**
    Return a mobile fat tree topology.
   */ 

#include "options.hpp"

/* Coordinates for visualization */
#define Y_ROOT          6
#define Y_CORE          4
#define Y_AGGREGATION   3
#define Y_EDGE          2
#define Y_LEAVES        1
#define Y_BOTTOM        0

#define MFT_BW_AGGR         1
#define MFT_BW_CORE_AGGR    1
#define MFT_BW_EDGE         1
#define MFT_BW_AGGR_EDGE    1
#define MFT_BW_EDGE_LEAVES  1
#define MFT_BW_X2           1

namespace ns3 {
namespace ndn {

class MobileFatTreeTopologyWithBorder : public NodeContainer {

public:
    MobileFatTreeTopologyWithBorder(NodeContainer & Leaves, Options & options, bool has_meshed_leaves = true);


    Ptr<Node>
    GetRoot();

    void
    GetRootNodes(NodeContainer &);

private:
    void
    addLink(Ptr<Node> n1, Ptr<Node> n2, std::string bandwidth);

    void
    addx2Link(Ptr<Node> n1, Ptr<Node> n2, std::string bandwidth);

    void
    LeafSetPosition(Ptr<Node> leaf, uint32_t x, uint32_t y);

    void try_to_add_x2_link(Ptr<Node> n1, Ptr<Node> n2, std::string bandwidth);
private:
    bool m_has_meshed_leaves;
    Options & m_options;
};

} // namespace ndn
} // namespace ns3

#endif // MOBILE_FAT_TREE_TOPOLOGY_HPP
