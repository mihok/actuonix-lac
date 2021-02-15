export declare type LACBoardPid = string;
export interface LACBoard {
    open: () => LACBoardPid;
    close: () => void;
}
export declare var LACBoard: {
    new (): LACBoard;
};
