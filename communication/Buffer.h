//
// Created by davide on 12/03/18.
//

#ifndef RESCUELINE_BUFFER_H
#define RESCUELINE_BUFFER_H

class Buffer {
private:
    uint8_t source;
    uint8_t type;
    uint8_t dataSize;
    uint8_t *data;

public:
    enum source_enum{SOURCE_RASPBERRY, SOURCE_ARDUINO};
    enum type_enum{TYPE_MOTORS, TYPE_IMU};

    explicit Buffer(uint8_t *buffer);
    explicit Buffer();
    virtual ~Buffer();

    uint8_t getSource() const;
    uint8_t getType() const;
    uint8_t getDataSize() const;
    uint8_t getHeaderSize() const;
    uint8_t length();
    void getData(uint8_t *&data);
    void cloneData(uint8_t *&data);

    void setSource(uint8_t source);
    void setType(uint8_t type);
    void setData(uint8_t *data, uint8_t size);

    void toBuffer(uint8_t *&buffer);
};


#endif //RESCUELINE_BUFFER_H
