import React, { Component } from 'react';
class Counter extends Component {
    state={
        count:1
    };
    render() { 
        return (
        <React.Fragment>
            <span class="badge badge-primary m-2">{this.formatCount()}</span>
            <button class="btn btn-danger">Increment</button>
        </React.Fragment>
        );
    }
    formatCount(){
        if(this.state.count==0){
            return 0;
        }
        else{
            return this.state.count;
        }
    }
}
 
export default Counter;