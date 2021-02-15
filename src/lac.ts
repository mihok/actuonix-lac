const lac = require('../build/Release/lac.node');

export type LACBoardPid = string;

export interface LACBoard {
    open: () => LACBoardPid;
    close: () => void;
}

export var LACBoard: {
    new(): LACBoard
} = lac.LACBoard;
