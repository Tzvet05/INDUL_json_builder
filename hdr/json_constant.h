#pragma once

/* ----- MACROS ----- */

// Head of the output Json file
#define JSON_FILE_HEAD	"{\"blueprint\":{\"icons\":[{\"signal\":{\"name\":\"constant-combinator\"},\"index\":1}],\"entities\":["

// Tail of the output Json file
#define JSON_FILE_TAIL	"],\"item\":\"blueprint\",\"label\":\"Instruction ROM\",\"version\":562949955518464}}"

// Json file content before the entity number field
#define JSON_FILE_ENTITY_NUMBER	"{\"entity_number\":"

// Json file content before the Y position field
#define JSON_FILE_ENTITY_POS_Y	",\"name\":\"constant-combinator\",\"position\":{\"x\":0,\"y\":"

// Json file content before the count field
#define JSON_FILE_ENTITY_COUNT	"},\"direction\":4,\"control_behavior\":{\"sections\":{\"sections\":[{\"index\":1,\"filters\":[{\"index\":1,\"type\":\"virtual\",\"name\":\"signal-0\",\"quality\":\"normal\",\"comparator\":\"=\",\"count\":"

// Json file content at the end of the entity
#define JSON_FILE_ENTITY_TAIL	"}]}]}}}"
