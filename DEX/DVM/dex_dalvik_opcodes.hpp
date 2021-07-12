/***
 * File: dex_dalvik_opcodes.hpp
 * Author: @Farenain
 * 
 * All the dalvik opcodes with information
 * of them, also strings will be used.
 * 
 * Based on dvm.py from Androguard.
 */

#ifndef DEX_DALVIK_OPCODES_HPP
#define DEX_DALVIK_OPCODES_HPP

#include <iostream>
#include <map>

#include "dex_dvm_types.hpp"
#include "dex_parser.hpp"


namespace KUNAI
{
    namespace DEX
    {

        class DalvikOpcodes
        {
        public:
            DalvikOpcodes(std::shared_ptr<DexParser> dex_parser);

            ~DalvikOpcodes();

            std::string get_instruction_name(std::uint32_t instruction);

            DVMTypes::Kind get_instruction_type(std::uint32_t instruction);

            DVMTypes::Operation get_instruction_operation(std::uint32_t instruction);

            std::string get_instruction_type_str(std::uint32_t instruction);
        
            std::string*    get_dalvik_string_by_id(std::uint32_t id);
            Type*           get_dalvik_Type_by_id(std::uint32_t id);
            FieldID*        get_dalvik_field_by_id(std::uint32_t id);
            MethodID*       get_dalvik_method_by_id(std::uint32_t id);
            ProtoID*        get_dalvik_proto_by_id(std::uint32_t id);


            std::string get_dalvik_string_by_id_str(std::uint32_t id);
            std::string get_dalvik_type_by_id_str(std::uint32_t id);
            std::string get_dalvik_static_field_by_id_str(std::uint32_t id);
            std::string get_dalvik_method_by_id_str(std::uint32_t id);
            std::string get_dalvik_proto_by_id_str(std::uint32_t id);

            void set_number_of_registers(std::uint32_t number_of_registers);
            void set_number_of_parameters(std::uint32_t number_of_parameters);
            std::uint32_t get_number_of_registers();
            std::uint32_t get_number_of_parameters();            
        private:
            std::uint32_t number_of_registers;
            std::uint32_t number_of_parameters;

            std::shared_ptr<DexParser> dex_parser;

            std::map<std::uint32_t, std::string> opcodes_instruction_name = {
                {0x00, "nop"},
                {0x01, "move"},
                {0x02, "move/from16"},
                {0x03, "move/16"},
                {0x04, "move-wide"},
                {0x05, "move-wide/from16"},
                {0x06, "move-wide/16"},
                {0x07, "move-object"},
                {0x08, "move-object/from16"},
                {0x09, "move-object/16"},
                {0x0A, "move-result"},
                {0x0B, "move-result-wide"},
                {0x0C, "move-result-object"},
                {0x0D, "move-exception"},
                {0x0E, "return-void"},
                {0x0F, "return"},
                {0x10, "return-wide"},
                {0x11, "return-object"},
                {0x12, "const/4"},
                {0x13, "const/16"},
                {0x14, "const"},
                {0x15, "const/high16"},
                {0x16, "const-wide/16"},
                {0x17, "const-wide/32"},
                {0x18, "const-wide"},
                {0x19, "const-wide/high16"},
                {0x1A, "const-string"},
                {0x1B, "const-string/jumbo"},
                {0x1C, "const-class"},
                {0x1D, "monitor-enter"},
                {0x1E, "monitor-exit"},
                {0x1F, "check-cast"},
                {0x20, "instance-of"},
                {0x21, "array-length"},
                {0x22, "new-instance"},
                {0x23, "new-array"},
                {0x24, "filled-new-array"},
                {0x25, "filled-new-array/range"},
                {0x26, "fill-array-data"},
                {0x27, "throw"},
                {0x28, "goto"},
                {0x29, "goto/16"},
                {0x2A, "goto/32"},
                {0x2B, "packed-switch"},
                {0x2C, "sparse-switch"},
                {0x2D, "cmpl-float"},
                {0x2E, "cmpg-float"},
                {0x2F, "cmpl-double"},
                {0x30, "cmpg-double"},
                {0x31, "cmp-long"},
                {0x32, "if-eq"},
                {0x33, "if-ne"},
                {0x34, "if-lt"},
                {0x35, "if-ge"},
                {0x36, "if-gt"},
                {0x37, "if-le"},
                {0x38, "if-eqz"},
                {0x39, "if-nez"},
                {0x3A, "if-ltz"},
                {0x3B, "if-gez"},
                {0x3C, "if-gtz"},
                {0x3D, "if-lez"},
                {0x3E, "unused"},
                {0x3F, "unused"},
                {0x40, "unused"},
                {0x41, "unused"},
                {0x42, "unused"},
                {0x43, "unused"},
                {0x44, "aget"},
                {0x45, "aget-wide"},
                {0x46, "aget-object"},
                {0x47, "aget-boolean"},
                {0x48, "aget-byte"},
                {0x49, "aget-char"},
                {0x4A, "aget-short"},
                {0x4B, "aput"},
                {0x4C, "aput-wide"},
                {0x4D, "aput-object"},
                {0x4E, "aput-boolean"},
                {0x4F, "aput-byte"},
                {0x50, "aput-char"},
                {0x51, "aput-short"},
                {0x52, "iget"},
                {0x53, "iget-wide"},
                {0x54, "iget-object"},
                {0x55, "iget-boolean"},
                {0x56, "iget-byte"},
                {0x57, "iget-char"},
                {0x58, "iget-short"},
                {0x59, "iput"},
                {0x5A, "iput-wide"},
                {0x5B, "iput-object"},
                {0x5C, "iput-boolean"},
                {0x5D, "iput-byte"},
                {0x5E, "iput-char"},
                {0x5F, "iput-short"},
                {0x60, "sget"},
                {0x61, "sget-wide"},
                {0x62, "sget-object"},
                {0x63, "sget-boolean"},
                {0x64, "sget-byte"},
                {0x65, "sget-char"},
                {0x66, "sget-short"},
                {0x67, "sput"},
                {0x68, "sput-wide"},
                {0x69, "sput-object"},
                {0x6A, "sput-boolean"},
                {0x6B, "sput-byte"},
                {0x6C, "sput-char"},
                {0x6D, "sput-short"},
                {0x6E, "invoke-virtual"},
                {0x6F, "invoke-super"},
                {0x70, "invoke-direct"},
                {0x71, "invoke-static"},
                {0x72, "invoke-interface"},
                {0x73, "unused"},
                {0x74, "invoke-virtual/range"},
                {0x75, "invoke-super/range"},
                {0x76, "invoke-direct/range"},
                {0x77, "invoke-static/range"},
                {0x78, "invoke-interface/range"},
                {0x79, "unused"},
                {0x7A, "unused"},
                {0x7B, "neg-int"},
                {0x7C, "not-int"},
                {0x7D, "neg-long"},
                {0x7E, "not-long"},
                {0x7F, "neg-float"},
                {0x80, "neg-double"},
                {0x81, "int-to-long"},
                {0x82, "int-to-float"},
                {0x83, "int-to-double"},
                {0x84, "long-to-int"},
                {0x85, "long-to-float"},
                {0x86, "long-to-double"},
                {0x87, "float-to-int"},
                {0x88, "float-to-long"},
                {0x89, "float-to-double"},
                {0x8A, "double-to-int"},
                {0x8B, "double-to-long"},
                {0x8C, "double-to-float"},
                {0x8D, "int-to-byte"},
                {0x8E, "int-to-char"},
                {0x8F, "int-to-short"},
                {0x90, "add-int"},
                {0x91, "sub-int"},
                {0x92, "mul-int"},
                {0x93, "div-int"},
                {0x94, "rem-int"},
                {0x95, "and-int"},
                {0x96, "or-int"},
                {0x97, "xor-int"},
                {0x98, "shl-int"},
                {0x99, "shr-int"},
                {0x9A, "ushr-int"},
                {0x9B, "add-long"},
                {0x9C, "sub-long"},
                {0x9D, "mul-long"},
                {0x9E, "div-long"},
                {0x9F, "rem-long"},
                {0xA0, "and-long"},
                {0xA1, "or-long"},
                {0xA2, "xor-long"},
                {0xA3, "shl-long"},
                {0xA4, "shr-long"},
                {0xA5, "ushr-long"},
                {0xA6, "add-float"},
                {0xA7, "sub-float"},
                {0xA8, "mul-float"},
                {0xA9, "div-float"},
                {0xAA, "rem-float"},
                {0xAB, "add-double"},
                {0xAC, "sub-double"},
                {0xAD, "mul-double"},
                {0xAE, "div-double"},
                {0xAF, "rem-double"},
                {0xB0, "add-int/2addr"},
                {0xB1, "sub-int/2addr"},
                {0xB2, "mul-int/2addr"},
                {0xB3, "div-int/2addr"},
                {0xB4, "rem-int/2addr"},
                {0xB5, "and-int/2addr"},
                {0xB6, "or-int/2addr"},
                {0xB7, "xor-int/2addr"},
                {0xB8, "shl-int/2addr"},
                {0xB9, "shr-int/2addr"},
                {0xBA, "ushr-int/2addr"},
                {0xBB, "add-long/2addr"},
                {0xBC, "sub-long/2addr"},
                {0xBD, "mul-long/2addr"},
                {0xBE, "div-long/2addr"},
                {0xBF, "rem-long/2addr"},
                {0xC0, "and-long/2addr"},
                {0xC1, "or-long/2addr"},
                {0xC2, "xor-long/2addr"},
                {0xC3, "shl-long/2addr"},
                {0xC4, "shr-long/2addr"},
                {0xC5, "ushr-long/2addr"},
                {0xC6, "add-float/2addr"},
                {0xC7, "sub-float/2addr"},
                {0xC8, "mul-float/2addr"},
                {0xC9, "div-float/2addr"},
                {0xCA, "rem-float/2addr"},
                {0xCB, "add-double/2addr"},
                {0xCC, "sub-double/2addr"},
                {0xCD, "mul-double/2addr"},
                {0xCE, "div-double/2addr"},
                {0xCF, "rem-double/2addr"},
                {0xD0, "add-int/lit16"},
                {0xD1, "rsub-int"},
                {0xD2, "mul-int/lit16"},
                {0xD3, "div-int/lit16"},
                {0xD4, "rem-int/lit16"},
                {0xD5, "and-int/lit16"},
                {0xD6, "or-int/lit16"},
                {0xD7, "xor-int/lit16"},
                {0xD8, "add-int/lit8"},
                {0xD9, "rsub-int/lit8"},
                {0xDA, "mul-int/lit8"},
                {0xDB, "div-int/lit8"},
                {0xDC, "rem-int/lit8"},
                {0xDD, "and-int/lit8"},
                {0xDE, "or-int/lit8"},
                {0xDF, "xor-int/lit8"},
                {0xE0, "shl-int/lit8"},
                {0xE1, "shr-int/lit8"},
                {0xE2, "ushr-int/lit8"},
                {0xE3, "unused"},
                {0xE4, "unused"},
                {0xE5, "unused"},
                {0xE6, "unused"},
                {0xE7, "unused"},
                {0xE8, "unused"},
                {0xE9, "unused"},
                {0xEA, "unused"},
                {0xEB, "unused"},
                {0xEC, "unused"},
                {0xED, "unused"},
                {0xEE, "unused"},
                {0xEF, "unused"},
                {0xF0, "unused"},
                {0xF1, "unused"},
                {0xF2, "unused"},
                {0xF3, "unused"},
                {0xF4, "unused"},
                {0xF5, "unused"},
                {0xF6, "unused"},
                {0xF7, "unused"},
                {0xF8, "unused"},
                {0xF9, "unused"},
                {0xFA, "invoke-polymorphic"},
                {0xFB, "invoke-polymorphic/range"},
                {0xFC, "invoke-custom"},
                {0xFD, "invoke-custom/range"},
                {0xFE, "const-method-handle"},
                {0xFF, "const-method-type"},
                // special cases...
                {0x0100, "packed-switch-payload"},
                {0x0200, "sparse-switch-payload"},
                {0x0300, "fill-array-data-payload"},
                {0xf2ff, "invoke-object-init/jumbo"},
                {0xf3ff, "iget-volatile/jumbo"},
                {0xf4ff, "iget-wide-volatile/jumbo"},
                {0xf5ff, "iget-object-volatile/jumbo"},
                {0xf6ff, "iput-volatile/jumbo"},
                {0xf7ff, "iput-wide-volatile/jumbo"},
                {0xf8ff, "iput-object-volatile/jumbo"},
                {0xf9ff, "sget-volatile/jumbo"},
                {0xfaff, "sget-wide-volatile/jumbo"},
                {0xfbff, "sget-object-volatile/jumbo"},
                {0xfcff, "sput-volatile/jumbo"},
                {0xfdff, "sput-wide-volatile/jumbo"},
                {0xfeff, "sput-object-volatile/jumbo"},
                {0xffff, "throw-verification-error/jumbo"}};

            std::map<std::uint32_t, DVMTypes::Kind> opcodes_instruction_type = {
                {0x1a, DVMTypes::Kind::STRING},
                {0x1b, DVMTypes::Kind::STRING},
                {0x1c, DVMTypes::Kind::TYPE},
                {0x1f, DVMTypes::Kind::TYPE},
                {0x20, DVMTypes::Kind::TYPE},
                {0x22, DVMTypes::Kind::TYPE},
                {0x23, DVMTypes::Kind::TYPE},
                {0x24, DVMTypes::Kind::TYPE},
                {0x25, DVMTypes::Kind::TYPE},
                {0x52, DVMTypes::Kind::FIELD},
                {0x53, DVMTypes::Kind::FIELD},
                {0x54, DVMTypes::Kind::FIELD},
                {0x55, DVMTypes::Kind::FIELD},
                {0x56, DVMTypes::Kind::FIELD},
                {0x57, DVMTypes::Kind::FIELD},
                {0x58, DVMTypes::Kind::FIELD},
                {0x59, DVMTypes::Kind::FIELD},
                {0x5a, DVMTypes::Kind::FIELD},
                {0x5b, DVMTypes::Kind::FIELD},
                {0x5c, DVMTypes::Kind::FIELD},
                {0x5d, DVMTypes::Kind::FIELD},
                {0x5e, DVMTypes::Kind::FIELD},
                {0x5f, DVMTypes::Kind::FIELD},
                {0x60, DVMTypes::Kind::FIELD},
                {0x61, DVMTypes::Kind::FIELD},
                {0x62, DVMTypes::Kind::FIELD},
                {0x63, DVMTypes::Kind::FIELD},
                {0x64, DVMTypes::Kind::FIELD},
                {0x65, DVMTypes::Kind::FIELD},
                {0x66, DVMTypes::Kind::FIELD},
                {0x67, DVMTypes::Kind::FIELD},
                {0x68, DVMTypes::Kind::FIELD},
                {0x69, DVMTypes::Kind::FIELD},
                {0x6a, DVMTypes::Kind::FIELD},
                {0x6b, DVMTypes::Kind::FIELD},
                {0x6c, DVMTypes::Kind::FIELD},
                {0x6d, DVMTypes::Kind::FIELD},
                {0x6e, DVMTypes::Kind::METH},
                {0x6f, DVMTypes::Kind::METH},
                {0x70, DVMTypes::Kind::METH},
                {0x71, DVMTypes::Kind::METH},
                {0x72, DVMTypes::Kind::METH},
                {0x74, DVMTypes::Kind::METH},
                {0x75, DVMTypes::Kind::METH},
                {0x76, DVMTypes::Kind::METH},
                {0x77, DVMTypes::Kind::METH},
                {0x78, DVMTypes::Kind::METH},
                {0xfa, DVMTypes::Kind::METH_PROTO},
                {0xfb, DVMTypes::Kind::METH_PROTO},
                {0xfc, DVMTypes::Kind::CALL_SITE},
                {0xfd, DVMTypes::Kind::CALL_SITE},
                {0xfe, DVMTypes::Kind::METH},
                {0xff, DVMTypes::Kind::PROTO},
                // special cases
                {0x0100, DVMTypes::Kind::NONE_KIND},
                {0x0200, DVMTypes::Kind::NONE_KIND},
                {0x0300, DVMTypes::Kind::NONE_KIND},
                {0xf2ff, DVMTypes::Kind::METH},
                {0xf3ff, DVMTypes::Kind::FIELD},
                {0xf4ff, DVMTypes::Kind::FIELD},
                {0xf5ff, DVMTypes::Kind::FIELD},
                {0xf6ff, DVMTypes::Kind::FIELD},
                {0xf7ff, DVMTypes::Kind::FIELD},
                {0xf8ff, DVMTypes::Kind::FIELD},
                {0xf9ff, DVMTypes::Kind::FIELD},
                {0xfaff, DVMTypes::Kind::FIELD},
                {0xfbff, DVMTypes::Kind::FIELD},
                {0xfcff, DVMTypes::Kind::FIELD},
                {0xfdff, DVMTypes::Kind::FIELD},
                {0xfeff, DVMTypes::Kind::FIELD},
                {0xffff, DVMTypes::Kind::VARIES}};

            // instructions that makes some specific operation
            // branch, break, read, write...
            std::map<std::uint32_t, DVMTypes::Operation> opcode_instruction_operation = {
                // branch instructions
                {0x27, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x32, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x33, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x34, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x35, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x36, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x37, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x38, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x39, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x3A, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x3B, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x3C, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x3D, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x28, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x29, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x2A, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x0E, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x0F, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x10, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x11, DVMTypes::Operation::BRANCH_DVM_OPCODE},
                {0x2B, DVMTypes::Operation::BRANCH_DVM_OPCODE}, // packed-switch
                {0x2C, DVMTypes::Operation::BRANCH_DVM_OPCODE}, // sparse-switch
                // break instruction
                {0x6E, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x6F, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x70, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x71, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x72, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x74, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x75, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x76, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x77, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x78, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x01, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x02, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x03, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x04, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x05, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x06, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x07, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x08, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x09, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x0A, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x0B, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x0C, DVMTypes::Operation::BREAK_DVM_OPCODE},
                {0x0D, DVMTypes::Operation::BREAK_DVM_OPCODE},
                // read field instruction
                {0x44, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x45, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x46, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x47, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x48, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x49, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x4A, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x52, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x53, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x54, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x55, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x56, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x57, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x58, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x60, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x61, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x62, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x63, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x64, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x65, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0x66, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0xf3ff, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0xf4ff, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0xf5ff, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0xf9ff, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0xfaff, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                {0xfbff, DVMTypes::Operation::FIELD_READ_DVM_OPCODE},
                // write field instruction
                {0x4B, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x4C, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x4D, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x4E, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x4F, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x50, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x51, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x59, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x5A, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x5B, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x5C, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x5D, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x5E, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x5F, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x67, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x68, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x69, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x6A, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x6B, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x6C, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0x6D, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0xf6ff, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0xf7ff, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0xf8ff, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0xfcff, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0xfdff, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
                {0xfeff, DVMTypes::Operation::FIELD_WRITE_DVM_OPCODE},
            };
        
        };
    }
}

#endif