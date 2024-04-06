from typing import Dict, List

class Node:
    def __init__(self, name: str, type: str, runHash: str):
        self.name = name
        self.type = type
        self.runHash = runHash

    @classmethod
    def parse_obj(cls, data: dict):
        # This method simulates parsing a dictionary to a Node object.
        # For simplicity, we'll return a Node object directly using the provided dictionary data.
        return cls(name=data.get("name"), type=data.get("type"), runHash=data.get("runHash"))

def find_nodes_with_attribute_value(nodes: Dict[str, dict], attribute: str, value: str) -> List[str]:
    # This function searches the nodes dictionary for nodes that have an attribute with the specified value.
    # It returns a list of node names (the 'name' attribute of each matching node).
    matching_nodes = []
    for node_id, node_data in nodes.items():
        node = Node.parse_obj(node_data)  # Parse the dictionary to a Node object.
        if getattr(node, attribute, None) == value:
            matching_nodes.append(node.name)
    return matching_nodes

# Test the function
workbench = {
    "89f95b67-a2a3-4215-a794-2356684deb61": {
        "name": "datacore",
        "type": "compute",
        "runHash": None,
    },
    "88119776-e869-4df2-a529-4aae9d9fa35c": {
        "name": "rawgraph",
        "type": "visualization",
        "runHash": "abc123",
    },
    "75c1707c-ec1c-49ac-a7bf-af6af9088f38": {
        "name": "simcore",
        "type": "simulation",
        "runHash": "def456",
    },
}

# Example usage
result = find_nodes_with_attribute_value(workbench, "type", "visualization")
print(result)  # Expected output: ["rawgraph"]